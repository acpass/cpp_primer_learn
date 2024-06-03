#include <iostream>
using namespace std;

enum { ACount = 0, ECount, ICount, OCount, UCount };

int main(int argc, char **argv) {
  string str;
  getline(cin, str);
  int count[5]{0, 0, 0, 0, 0};
  for (auto &i : str) {
    switch (i) {
    case 'a':
      count[ACount]++;
      break;
    case 'e':
      count[ECount]++;
      break;
    case 'i':
      count[ICount]++;
      break;
    case 'o':
      count[OCount]++;
      break;
    case 'u':
      count[UCount]++;
      break;
    default:
      break;
    }
  }

  cout << "count of a: " << count[ACount] << endl;
  cout << "count of e: " << count[ECount] << endl;
  cout << "count of i: " << count[ICount] << endl;
  cout << "count of o: " << count[OCount] << endl;
  cout << "count of u: " << count[UCount] << endl;

  return 0;
}