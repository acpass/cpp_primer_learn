#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> process(string str1, string str2)
{
  return {"str1:", str1, "\n", "str2:", str2, "\n"};
}

int main()
{
  string str1, str2;
  cin >> str1 >> str2;
  for (auto &i : process(str1, str2))
  {
    cout << i;
  }
  cout << str1;
  return 0;
}