#include <iostream>
#include <string>
using namespace std;

typedef struct itn {
  int num;
  string str;
} itn;

itn &newitn(int num, string str) {  // lvalue
  itn *stru = new (itn);
  stru->num = num;
  stru->str = str;
  cout << stru << endl;
  return *stru;
}

int main() {
  int a = 1;
  string str = "sss";
  itn &test = newitn(a, str);
  itn test1 = newitn(a, str);
  cout << '1' << endl;
  test.num = 5;
  cout << test.num << test.str << endl;
  cout << test1.num << test1.str << endl;
  cout << newitn(a, str).num << '\n' << newitn(a, str).str << endl;
  cout << &test << ' ' << &test1 << endl;
  return 0;
}