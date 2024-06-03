#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
using namespace std;

void compare_and_throw(string str1, string str2) {
  if (str1 == str2)
    throw runtime_error("input two different words");
  return;
}

int main() {
  string str1, str2;

  for (; cin >> str1 >> str2;) {

    try {
      compare_and_throw(str1, str2);
    } catch (runtime_error err) {
      cout << err.what() << '\n';
      cout << "please input again." << endl;
      continue;
    }
    cout << str1 << str2 << endl;
  }
  return 0;
}