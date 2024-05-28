#include "inherit.hpp"
#include <iostream>

int main()
{
  name_hidden_derived obj(1);
  hidden_test(obj);
  // obj.foo_hidden_test();   //error: derived classes can not overload functions in their direct base class
  obj.name_hidden_base::foo_hidden_test();
  obj.base_foo();
  obj.name_hidden_derived::base_foo();
}