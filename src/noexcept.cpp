
#include <print>
#include <stdexcept>
class test_class {
public:
  test_class() { std::println("class_init"); }
  ~test_class() { std::println("class_destroy"); };
};

void thrower() {
  test_class t;
  throw std::runtime_error("thrower");
}

void foo() noexcept {
  test_class t;
  std::println("foo");
  thrower();
}

int main() { foo(); }