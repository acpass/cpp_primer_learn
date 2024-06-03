#include <array>
#include <iostream>

using namespace std;

int arr[10];

auto arrgen(unsigned int i) -> int (*)[10] {
  int a = 0;
  for (auto beg = begin(arr), en = end(arr); beg != en; ++beg, ++a) {
    arr[a] = i;
  }
  return &(arr);
}

int main() {
  arrgen(42);
  int i = 0;
  for (auto beg = begin(arr), en = end(arr); beg != en; ++beg, ++i) {
    cout << arr[i];
  }
  return 0;
}
