#include <iostream>
using namespace std;

int (*fun())(int, int);

int main() {
  int (*b)(int, int) = fun();
  cout << b(1, 1) << endl;
  return 0;
}

int a(int s, int h) { return 1; }

int (*fun())(int, int) { return a; }