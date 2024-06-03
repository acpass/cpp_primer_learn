#include "strBlob.hpp"
#include <iostream>
#include <string>

int main() {
  strBlob b1;
  {
    strBlob b2{"a", "b", "c"};
    b1 = b2;
    b2.push_back("123");
  }
  while (!b1.empty()) {
    std::cout << b1.back() << ' ';
    b1.pop_back();
  }
  std::cout << std::endl;
}