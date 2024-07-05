
#include <thread>
class RAIIthread {
public:
  enum class Policy { join, detach };
  RAIIthread(Policy p = Policy::join) : policy(p) {}

  template <typename... ARGS>
  RAIIthread(Policy p, ARGS &&...args)
      : t(std::forward<ARGS>(args)...), policy(p) {}

  RAIIthread(RAIIthread &&t) : t(std::move(t.t)), policy(t.policy) {}

  ~RAIIthread() {
    if (t.joinable()) {
      if (policy == Policy::join) {
        t.join();
      } else {
        t.detach();
      }
    }
  }

private:
  Policy policy;
  std::thread t;
};