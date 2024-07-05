
#include <print>

static inline void foo() { std::println("unit2"); }

extern void callfoo();

int main() {
  foo();
  callfoo();
  return 0;
}