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
  mutable int ma;

public:
  constexpr test_class(int b, int c)
      : a(b), ma(c){};
  constexpr test_class()
      : test_class(1, 2){};

  void set(int b, int c)
  {
    a = b;
    ma = c;
  }
  void set_m(int b)
  {
    ma = b;
  }
  constexpr int get_a() const
  {
    return a;
  }
  constexpr int get_ma()
  {
    return ma;
  }
};

#endif