#include "constructor.hpp"
#include <functional>
#include <iostream>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
using std::cin;
using std::cout;
using std::endl;

void foo(deleted_copy) { cout << "foo called" << endl; }

int main() {
  cout << "1" << endl;
  deleted_copy s(1);
  int a = 1;

  int &&rv2 = +a;
  rv2 = 2;

  int &&rv3 = std::move(a);
  rv3 = 3;

  cout << a << ' ' << rv2 << endl;

  hasY y1;
  hasY y3(y1);
  hasY y2(std::move(y1));

  std::vector<std::string> sv;
  std::string s1("123");
  sv.push_back(s1);
  s1[0] = '3';
  cout << s1 << ' ' << sv[0] << endl;

  cout << cin.fail() << endl;
  cin.setstate(std::ios_base::failbit);
  cin.clear();
  cout << cin.fail() << endl;

  int captured_v = 1;

  auto lambda_obj = [captured_v]() -> int { return captured_v; };

  // auto v = lambda_obj.operator()();

  std::function<int()> f1 = lambda_obj;

  cout << "function return: " << f1() << endl;

  myclass v1(2);

  // cout << v1 + 1 << endl;
  cout << v1.operator+(1) << endl;

  Init_Assign ia1(1);
  Init_Assign ia2 = ia1;
  Init_Assign ia3 = 1;
  ia3 = 2;
  Init_Assign ia4{1};

  std::tuple<int, double, std::string> tup = {1, 2.5, "123"};

  return 0;
}