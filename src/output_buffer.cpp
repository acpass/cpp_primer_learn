#include <iostream>
using namespace std;

int main()
{
  cout << cin.tie() << endl;
  cout << unitbuf;
  cout << cin.tie() << endl;
  cout << cout.tie() << endl;
  cout << cerr.tie() << endl;

  ostream *old_tie = cin.tie(nullptr);

  cout << cin.tie() << endl;
  cout << old_tie << endl;

  cout << "test " << endl;
  cout << "test " << flush;
  cout << "test " << ends;
  return 0;
}