#include <algorithm>
#include <iostream>
#include <list>
#include <numeric>
#include <vector>

using namespace std;

int main() {
  int a[]{1, 2, 3, 4, 5, 6, 7};
  auto ans = find(begin(a), end(a), 4);
  if (ans != end(a))
    cout << *ans;
  else
    cout << "no present";

  cout << endl;
  vector<string> s{"1", "2", "3", "4"};
  string sum = accumulate(s.cbegin(), s.cend(), string("5"));
  cout << sum << endl;
  cout << equal(s[0].cbegin(), s[0].cend(), sum.cbegin()) << endl;
  // cout << equal(s.cbegin(), s.cend(), sum.cbegin()) << endl;

  auto insert_iter = back_inserter(sum);
  *insert_iter = 'a';
  *insert_iter = 'b';
  *insert_iter = 'c';
  cout << sum << endl;
  // following codes are wrong, because a deref to a insert_iter call a member
  // named exactly push_back(...) but forward_list does not have such member
  //  forward_list<int> flst{1, 2, 3};
  //  for (auto i : flst)
  //  {
  //    cout << i << ' ';
  //  }
  //  cout << endl;

  // auto forward_insert_iter = back_inserter(flst);
  // *forward_insert_iter = 4;
  // *forward_insert_iter = 5;
  // for (auto i : flst)
  // {
  //   cout << i << ' ';
  // }
  // cout << endl;

  string dest;
  auto dest_insert = back_inserter(dest);
  copy(sum.cbegin(), sum.cend(),
       dest_insert); //+ is overloaded for a insert iterator, which return the
                     // iterator itself
  cout << dest << endl;

  string line{"12312321412318"};
  cout << line << endl;
  sort(line.begin(), line.end(), [](char a, char b) -> bool { return a > b; });
  auto line_unique_end = unique(line.begin(), line.end());
  line.erase(line_unique_end, line.end());
  cout << line << endl;

  vector<string> sv{"1231231", "2131", "21312312", "3123", "2311311", "213"};
  auto last_true = partition(sv.begin(), sv.end(), [](const string &a) -> bool {
    return a.size() < 5;
  });
  for (auto i : sv) {
    cout << i << ' ';
  }
  cout << endl;
  for (; last_true != sv.end(); last_true++) {
    cout << *last_true << ' ';
  }
  // last_true point to the element one past the last element returned true
  cout << endl;

  list<int> lst1{6, 3, 8}, lst2{1, 4, 9};
  lst1.merge(lst2);
  ostream_iterator<int> out_iter(cout, " ");
  copy(lst1.cbegin(), lst1.cend(), out_iter);
  cout << endl;
  copy(lst2.cbegin(), lst2.cend(), out_iter); // empty
  cout << endl;

  return 0;
}