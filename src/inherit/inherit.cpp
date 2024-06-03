#include "inherit.hpp"
#include <iostream>

void hidden_test(const name_hidden_base &obj) {
  std::cout << obj.get_mem() << std::endl;
}