#include <iostream>
#include "static_member.hpp"

int main()
{
  test_class obj1, obj2;
  obj1.call_count();
  obj2.call_count();
  obj1.call_count();

  std::cout << obj1.var() << std::endl;
  std::cout << test_class::var() << std::endl;
  std::cout << obj2._var() << std::endl;
  std::cout << obj2.var() << std::endl;
}