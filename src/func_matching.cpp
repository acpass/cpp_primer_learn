#include <iostream>
using namespace std;

void func(long a) { cout << __func__ << endl; }

void func(short a) { cout << __func__ << endl; }

void func(int a) {
  cout << __func__ << endl;
  cout << 1 << endl;
}

int main() {
  func('a');
  return 0;
}