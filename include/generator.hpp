#include <concepts>
#include <coroutine>
#include <exception>
#include <print>
#include <type_traits>
#include <utility>
template <typename T> class generator {
public:
  class ExhaustedException : public std::exception {
    const char *what() const noexcept override { return "Generator exhausted"; }
  };

  struct promise_type {
    T current_value;       // store the current value
    bool is_ready = false; // indicate whether the value is ready

    generator<T> get_return_object() {
      return generator{
          std::coroutine_handle<promise_type>::from_promise(*this)};
    }

    std::suspend_always initial_suspend() { return {}; }
    std::suspend_always final_suspend() noexcept { return {}; }

    std::suspend_always yield_value(T value) {
      current_value = value;
      is_ready = true;
      return {};
    }

    void unhandled_exception() { std::terminate(); }
  };

  generator(std::coroutine_handle<promise_type> h) : handler(h) {}

  generator(generator &&rhs) : handler(std::exchange(rhs.handler, {})) {}

  generator(generator const &) = delete;
  auto operator=(generator const &) -> generator & = delete;

  ~generator() {
    std::println("handler destroy");
    if (handler)
      handler.destroy();
  }

  bool has_next() {
    if (handler.done())
      return false;

    if (!handler.promise().is_ready) {
      handler.resume();
    }

    if (handler.done())
      return false;
    else
      return true;
  }

  T next() {
    if (has_next()) {
      handler.promise().is_ready = false;
      return handler.promise().current_value;
    } else {
      throw ExhaustedException{};
    }
  }

  template <typename... ARGS> generator static from(ARGS... args) {
    (co_yield args, ...);
  };

  template <typename F> generator<std::invoke_result_t<F, T>> map(F f) & {
    std::println("map called");
    while (has_next()) {
      co_yield f(next());
    }
  }

  template <typename F> generator<std::invoke_result_t<F, T>> map(F f) && {
    return [&f](generator<T> g) -> generator<std::invoke_result_t<F, T>> {
      while (g.has_next()) {
        co_yield f(g.next());
      }
    }(std::move(*this));
  }

  template <typename F> auto filter(F f) & {
    while (has_next()) {
      auto value = next();
      if (f(value)) {
        co_yield value;
      }
    }
  }

  template <typename F> auto filter(F f) && {
    return [&f](generator<T> g) -> generator<T> {
      while (g.has_next()) {
        auto value = g.next();
        if (f(value)) {
          co_yield value;
        }
      }
    }(std::move(*this));
  }

private:
  std::coroutine_handle<promise_type> handler;
};
