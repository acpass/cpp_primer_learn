#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
  int test_cnt;
  cin >> test_cnt;
  vector<int> solve;

  while (test_cnt--)
  {
    vector<ll>::size_type n;
    cin >> n;
    vector<ll> a;
    int max = 0, prev;

    if (n == 0)
    {
      solve.push_back(0);
      continue;
    }
    for (int i = 0; i < n; ++i)
    {
      ll tmp;
      cin >> tmp;
      a.push_back(tmp);
    }

    // cout << "tt " << endl;
    sort(a.begin(), a.end());
    decltype(a) uni_a;
    prev = a[0];
    uni_a.push_back(prev);
    for (auto beg = a.begin() + 1, en = a.end(); beg != en; beg++)
    {
      if (*beg == prev)
      {
        continue;
      }
      else
      {
        uni_a.push_back(*beg);
      }
    }

    // cout << "tt " << endl;
    auto iter_search = uni_a.begin(), iter_head = uni_a.begin();
    auto iter_end = uni_a.end();
    vector<pair<decltype(uni_a.begin()), decltype(uni_a.begin())>> range_pair;

    // cout << "tt " << endl;
    while (iter_search != iter_end)
    {
      if ((*iter_search - *iter_head) < n)
      {
        iter_search++;
      }
      else
      {
        pair<decltype(uni_a.begin()), decltype(uni_a.begin())> tmp(iter_search - 1, iter_head);
        range_pair.push_back(tmp);
        iter_head++;
      }
    }
    if ((*(iter_search - 1) - *iter_head) <= n)
    {
      pair<decltype(uni_a.begin()), decltype(uni_a.begin())> tmp(iter_search - 1, iter_head);
      range_pair.push_back(tmp);
    }
    // cout << "tt " << endl;
    for (auto i : range_pair)
    {
      int diff = i.first - i.second + 1;
      if (diff > max)
        max = diff;
    }

    // cout << "tt " << endl;
    solve.push_back(max);
  }

  for (auto i : solve)
  {
    cout << i << '\n';
  }
  cout << endl;
}