#include <iostream>
using namespace std;

void print(int) { cout << __func__ << endl; }

void print(long) { cout << __func__ << endl; }

int main() {
  print(static_cast<int>(1));
  print(static_cast<long>(1));

  return 0;
}