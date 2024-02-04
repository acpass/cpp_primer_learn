#include <iostream>
using namespace std;

int func(int a)
{
  return a;
}

int (*func_retfunc())(int)
{
  return func;
}

using func_alias = decltype(func); // func_alias is a function type

func_alias *func_retfunc2() // should write the return type of func pointer explicitly
{
  return func;
}

using func_pointer = decltype(func) *; // decltype return a function type instead of a pointer to function type
typedef int (*func_pointer2)(int);

int main()
{
  int (&rf)(int) = func;
  int (*pf)(int) = func;
  func_pointer pf2 = func;
  func_pointer2 pf3 = func;
  func_pointer pf4 = func_retfunc();
  func_alias *pf5 = func_retfunc2();
  cout << rf(12) << ' ' << pf(11) << pf4(321) << endl;
  return 0;
}