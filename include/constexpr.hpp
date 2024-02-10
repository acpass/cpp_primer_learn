#ifndef _CONSTEXPR_HPP_
#define _CONSTEXPR_HPP_

#include <string>
int main();

#define SHOW(a)                              \
  {                                          \
    std::cout << #a " = " << a << std::endl; \
  }

constexpr int NUM1 = 2;
constexpr int NUM2 = 3;
constexpr int *POINTER1 = nullptr;
constexpr const int *POINTER2 = &NUM1;
constexpr int (*POI)() = main;

constexpr int add(const int a, const int b)
{
  return a + b;
}

#endif