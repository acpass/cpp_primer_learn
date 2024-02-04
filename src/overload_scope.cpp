#include <iostream>
#include <string>
using namespace std;

void print(string);
void print(long);

int main()
{
  int a = 1;
  long b = 2;
  string s = "1";
  void print(int);
  print(a);
  print(b);
  // print(s);

  return 0;
}

void print(string str)
{
  cout << "string" << endl;
}

void print(long lon)
{
  cout << "long" << endl;
}

void print(int i)
{
  cout << "int" << endl;
}