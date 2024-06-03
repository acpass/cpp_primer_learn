#include "static_member.hpp"
#include <iostream>

int test_class::initvar1() {
  std::cin >> var1;
  return var1;
}

int test_class::_initvar1() {
  std::cin >> var1;
  return var1;
}

test_class obj;

int test_class::var1 =
    obj.initvar1(); // equa to test_class::initvar1(), may because a call to
                    // static member will not transit this pointer as a
                    // parameter