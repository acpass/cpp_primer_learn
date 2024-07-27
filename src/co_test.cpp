
#include <coroutine>
#include <cstddef>
#include <print>

template <typename T = void> class promiseType;

template <typename T = void> class Task {
public:
  using promise_type = promiseType<T>;

  auto await_ready() noexcept { return false; }

  auto await_suspend(std::coroutine_handle<promise_type> callerHandle);

  auto await_resume();
  // define later

  Task(std::coroutine_handle<promise_type> handle) : handle(handle) {}

  ~Task() {
    if (handle)
      handle.destroy();
  }

  std::coroutine_handle<promise_type> handle;
};

class suspendReturnCoroutine {
public:
  bool await_ready() noexcept { return false; }

  auto
  await_suspend(std::coroutine_handle<>) noexcept -> std::coroutine_handle<> {
    if (handle) {
      return handle;
    } else {
      return std::noop_coroutine();
    }
  }

  auto await_resume() noexcept { return; }

  suspendReturnCoroutine(std::coroutine_handle<> h) : handle(h) {};

  std::coroutine_handle<> handle;
};

template <typename T> class promiseType {
public:
  Task<T> get_return_object() {
    return Task{std::coroutine_handle<promiseType>::from_promise(*this)};
  }

  auto initial_suspend() noexcept { return std::suspend_always{}; }

  auto final_suspend() noexcept { return std::suspend_always{}; }

  auto unhandled_exception() noexcept { std::terminate(); }

  auto yield_value(T v) {
    returnValue = v;
    return suspendReturnCoroutine{prevHandle};
  }

  // auto return_value(T v) {
  //   returnValue = v;
  //   return suspendReturnCoroutine{prevHandle};
  // }

  void return_void() { return; }

  std::coroutine_handle<promiseType> prevHandle = nullptr;
  T returnValue;
};

template <typename T>
auto Task<T>::await_suspend(std::coroutine_handle<promise_type> callerHandle) {
  handle.promise().prevHandle = callerHandle;
  return handle;
}

template <typename T> auto Task<T>::await_resume() {
  return handle.promise().returnValue;
}

Task<int> co_test1() {
  std::println("enter co_test1");
  co_yield 1;
  std::println("yield 1 time from 1");
  co_yield 2;
  std::println("end 1");
}

Task<int> co_test2() {
  std::println("enter co_test2");
  co_yield 2;
  std::println("before co_test1");

  co_await co_test1();

  std::println("after co_test1");
  co_yield 3;
  co_yield 5;
  std::println("end co_test2");
}

int main() {
  auto t = co_test2();
  std::println("before co_test2");

  while (!t.handle.done()) {
    t.handle.resume();
    std::println("get value {}", t.handle.promise().returnValue);
  }

  std::println("after co_test2");
  return 0;
}