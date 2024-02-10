#include <iostream>
#include "aggregate_class.hpp"

int main()
{
  test_class obj1 = {1, 1, "a"};
  test_class obj2{2, 2, "b"};
  test_class obj3({3, 3, "c"});
  obj1 = {4, 4, "a"};
  std::cout << obj1.a << ' ' << obj1.b << ' ' << obj1.str << std::endl;
  std::cout << obj2.a << ' ' << obj2.b << ' ' << obj2.str << std::endl;
  std::cout << obj3.a << ' ' << obj3.b << ' ' << obj3.str << std::endl;
  return 0;
}