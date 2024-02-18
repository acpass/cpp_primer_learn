#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
  unsigned int test_cnt;
  cin >> test_cnt;

    while (test_cnt--)
  {
    int n;
    cin >> n;
    vector<ll> a;

    for (auto i = 0; i < n; i++)
    {
      ll tmp;
      cin >> tmp;
      a.push_back(tmp);
    }

    sort(a.begin(), a.end());

    for (int i = 0, n = 0; i < n; i++, n++)
    {
      a[i] += i + 1 - n;
    }

    vector<ll> b;

    ll prev = a[n - 1];
    b.push_back(prev);
    for (auto beg = a.rbegin(), en = a.rend(); beg != en; beg++)
    {
      if (*beg == prev)
        continue;
      else
      {
        b.push_back(*beg);
        prev = *beg;
      }
    }

    for (auto i : b)
    {
      cout << i << ' ';
    }
    cout << endl;
  }
  return 0;
}