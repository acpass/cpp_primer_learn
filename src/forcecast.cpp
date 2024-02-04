#include <iostream>
using namespace std;

int main()
{
  int a = -56;
  int *p = &a;
  void *vp = nullptr;
  vp = p;
  int *lp = reinterpret_cast<int *>(vp);
  // int *llp = vp;  illegal
  int *lllp = static_cast<int *>(vp);
  cout << vp << lp << lllp << endl;
  return 0;
}