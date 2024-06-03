#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> v = {1, 2, 3};
  int a(0);
  for (auto i : v) // v.end() is extracted from v, .i.e 3, so the loop is
                   // iterated for 3 times
  {
    v.push_back(12);
    a++;
  }
  cout << a << endl;
  cout << v.size() << endl;
  return 0;
}