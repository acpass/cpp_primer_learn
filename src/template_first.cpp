#include "template_first.hpp"

#include <string>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void real_foo(int a, int &b, int &&c)
{
  b += 1;
  cout
      << "succussful called" << endl;
}

int main()
{
  cout << template_add(1, 2) << endl;
  cout << template_add(3, 2) << endl;
  std::string s1("123"), s2("234");
  cout << template_add(s1, s2) << endl;
  cout << std::less()(1, 2) << endl;
  cout << endl;

  std::string s_arr[3] = {"a", "2", "2"};
  auto s_point = s_arr;
  cout << array_size(s_arr) << endl;
  cout << array_size("121") << endl;
  cout << endl;

  int b = 2;
  proxy_foo(1, b, 3);
  cout << "b: " << b << endl;
}