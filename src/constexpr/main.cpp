#include <iostream>
#include "constexpr.hpp"

int main()
{
  int a = 1, b = 2;
  std::cin >> a >> b;
  std::cout << add(NUM1, NUM2) << std::endl;
  std::cout << add(3, 4) << std::endl;
  std::cout << add(a, b) << std::endl;
  constexpr int c = add(NUM1, NUM2);
  std::cout << c << std::endl;
  SHOW(POI);
  SHOW(POINTER1);
  SHOW(POINTER2);
  return 0;
}