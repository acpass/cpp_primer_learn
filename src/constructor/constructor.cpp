#include <iostream>
#include "constructor.hpp"

Constructor &Constructor::operator=(const Constructor &c)
{
  this->a = c.a;
  std::cout << "operator = invoked\n";
  return *this;
}