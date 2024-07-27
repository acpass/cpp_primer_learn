#include "RTTI.hpp"
#include <iostream>
#include <ostream>
#include <typeinfo>

int main() {
  Base b1(1), b2(2);
  Derived d1(1, 2), d2(2, 2), d3(1, 2);
  // std::cout << (b1 == b2) << (d1 == b1) << (d1 == d2) << (d1 == d3)
  // << std::endl;
  std::cout << typeid(Base).name();
  return 0;
}