#include <bits/stdc++.h>
using namespace std;

int main()
{
  ostream_iterator<char> os_iter(cout);
  string s{"sdasdasdasd"};
  ostringstream oss;
  ostream_iterator<char> oss_iter(oss);
  partition_copy(s.cbegin(), s.cend(), os_iter, oss_iter, [](char c) {
    return c == 'a' ? 1 : 0;
  });
  cout << endl;

  cout << oss.str() << endl;

  ofstream fd_out("/root/code/CPP_learn/test_file/write/is_iter_test");
  if (fd_out.is_open())
  {
    istream_iterator<char> is_iter(cin);
    istream_iterator<char> eof;
    ostream_iterator<char> of_iter(fd_out);

    while (is_iter != eof)
    {
      *of_iter = *is_iter++;
      of_iter++;
    }
  }
  else
  {
    cout << "failed to open file" << endl;
  }
  return 0;
}