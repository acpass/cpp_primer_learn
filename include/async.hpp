
#include <thread>
class RAIIthread {
public:
  enum class Policy { join, detach };
  RAIIthread(Policy p = Policy::join) : policy(p) {}

  template <typename... ARGS>
  RAIIthread(Policy p, ARGS &&...args)
      : policy(p), t(std::forward<ARGS>(args)...) {}

  RAIIthread(RAIIthread &&t) : policy(t.policy), t(std::move(t.t)) {}

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