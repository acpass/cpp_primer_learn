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
    cout << "failed to open file";
  }
  cout << endl;

  ifstream fd_in("../test_file/file1");
  if (fd_in.is_open())
  {
    istream_iterator<string> inf_iter1(fd_in), inf_iter2(fd_in), eof;
    ostream_iterator<string> os_iter(cout, " ");

    while (inf_iter1 != eof && inf_iter2 != eof)
    {
      *os_iter = *inf_iter1++;
      *os_iter = *inf_iter2++;
      //dereference just return a element bound to the iterator (read previously), it is the ++ operator who really read a element from the stream
      //except for the first read, which should be done when initializing but can be delay to sync different iterator bound to the same stream (lazy read)
    }
    cout << "$eof$";
    cout << endl;
  }
  else
  {
    cout << "failed to open file" << endl;
  }
  fd_in.close();

  string s2{"12,321,12,5325,234,6436,dfsd"};
  auto last_word = find(s2.crbegin(), s2.crend(), ',');
  cout << string(last_word.base(), s2.crbegin().base()) << endl; //base() return the next iterator for a "normal" last_word

  return 0;
}