#include <iostream>
using namespace std;

void print(int a) { cout << __func__ << endl; }

void print(long a) { cout << __func__ << endl; }

int main() {
  print(static_cast<int>(1));
  print(static_cast<long>(1));

  return 0;
}