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
    vector<pair<ll, ll>> a;
    for (int i = 1; i <= n / 2 + 1; i++)
    {
      int div;
      for (div = 2 * i; div <= n; div++)
      {
        if (!(div % i))
        {
          a.emplace_back(div, i);
        }
      }
      if (a.size() == 2)
        break;
    }
    ll num1, num2, num3, num4;
    num1 = a[0].second;
    num2 = a[0].first;
    num3 = a[1].second;
    num4 = a[1].first;

    if (num2 == num3)
      cout << num1 << ' ' << num2 << ' ' << num4 << ' ';
    else if (num1 == num3)
      cout << num2 << ' ' << num1 << ' ' << num4;
    else
      cout << num1 << ' ' << num3 << ' ' << num2 << ' ' << num4 << ' ';

    for (ll i = 1; i <= n; i++)
    {
      if (i != num1 && i != num2 && i != num3 && i != num4)
        cout << n << ' ';
    }

    cout << endl;
  }
  return 0;
}