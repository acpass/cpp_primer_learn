#include <iostream>
using namespace std;

void func(long) { cout << __func__ << endl; }

void func(short) { cout << __func__ << endl; }

void func(int) {
  cout << __func__ << endl;
  cout << 1 << endl;
}

int main() {
  func('a');
  return 0;
}