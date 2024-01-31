#include <iostream>
using namespace std;

void print(int a = 1, int b = 2)
{
  cout << a << ' ' << b << endl;
}

void print(char a = 'a', char b = 'b')
{
  cout << a << ' ' << b << endl;
}

void print()
{
  cout << "none" << endl;
}

int main()
{
  int a = 3;
  int c = 'c';
  // print();   ambiguous ->  illegal
  print(a, a);
  print(c, c);
}