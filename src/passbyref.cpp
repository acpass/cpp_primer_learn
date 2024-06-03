#include <iostream>
using namespace std;

int swap(int &a, int &b) {
  a = a ^ b;
  b = a ^ b;
  a = a ^ b;
  return 0;
}

int main() {
  int a = 1, b = 2;
  swap(a, b);
  cout << a << b << endl;
  return 0;
}
