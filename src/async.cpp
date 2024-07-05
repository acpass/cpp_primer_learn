
#include "async.hpp"
#include <atomic>
#include <print>
#include <thread>
#include <vector>

int foo(int tid) {
  static std::atomic<int> cnt = 0;
  std::println("called by {}", tid);
  return cnt++;
}

void RAIItest() { RAIIthread t1(RAIIthread::Policy::join, foo, 1); }

int main() {
  std::vector<std::thread> threads;

  // try {
  //   while (1)
  //     threads.emplace_back(foo, threads.size());
  // } catch (std::system_error &e) {
  //   std::println("Exception: {}", e.what());
  //   for (auto &t : threads) {
  //     t.join();
  //   }
  //   threads.clear();
  //   std::println("exception resolved");
  // }

  RAIItest();
}