
#include <chrono>
#include <print>
#include <thread>

using namespace std::literals;

int main() {
  auto t1 = std::chrono::high_resolution_clock::now();
  std::this_thread::sleep_for(300ms);
  auto t2 = std::chrono::high_resolution_clock::now();
  std::println(
      "time passed {} ms",
      std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count());

  return 0;
}