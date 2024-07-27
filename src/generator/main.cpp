#include "generator.hpp"
#include <print>

int main() {
  std::println("main called");

  auto gen = generator<int>::from(1, 2, 3, 4, 5)
                 .map([](int x) { return x * 2; })
                 .filter([](int x) { return x % 2 == 0; });

  std::println("before use");
  while (gen.has_next()) {
    auto value = gen.next();
    std::println("{}", value);
  }
}