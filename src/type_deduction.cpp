#include <iostream>
#include <ostream>
#include <string>
#include <tuple>

int func_re_int() { return 1; }

int main() {
  std::tuple<int, double, std::string> tup = {1, 2.5, "123"};
  std::cout << std::get<1>(tup) << std::endl;

  // int a = 1;

  // auto &&rr1 = 3;
  // auto &&ur2 = a;

  // auto &lr = a;
  // auto lr2 = lr;
  // decltype(auto) lr3 = lr;

  // decltype((a)) x = a;

  return 0;
}