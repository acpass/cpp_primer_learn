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
constexpr const int *POINTER2 = &NUM1; // constexpr indicate a top-level const
constexpr int (*POI)() = main;

// constexpr function: return type and parameter types must be all literal types
// it can be used to add two non-const nums and return a non-const num
// but in a situation where a constexpr is needed, it must give a constexpr
constexpr int add(const int a, const int b)
{
  return a + b;
}

class test_class
{
private:
  int a;

public:
  constexpr test_class(int b)
      : a(b){};
  test_class()
      : a(1){};

  void set(int b)
  {
    a = b;
  }
  constexpr int get() const
  {
    return a;
  }
};

#endif