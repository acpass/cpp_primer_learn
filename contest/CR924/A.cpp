#include <bits/stdc++.h>
using namespace std;

using ll = long long;

inline bool check(ll, ll);

int main()
{
  int test_cnt;
  cin >> test_cnt;

  while (test_cnt--)
  {
    ll a, b;
    cin >> a >> b;
    if (a < b)
      swap(a, b);
    if (check(a, b) || check(b, a))
      cout << "yes" << endl;
    else
      cout << "no" << endl;
  }
}

inline bool check(ll a, ll b)
{
  if (a % 2)
    return 0;
  if (a / 2 == b)
    return 0;
  return 1;
}