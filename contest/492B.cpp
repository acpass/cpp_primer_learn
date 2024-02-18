#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
  ll n, l;
  cin >> n >> l;
  vector<ll> lantern(n);

  for (ll i = 0; i < n; ++i)
  {
    cin >> lantern[i];
  }

  sort(lantern.begin(), lantern.end());

  ll maxd = 2 * max(lantern[0], l - lantern[n - 1]);

  for (ll i = 0; i < lantern.size() - 1; ++i)
  {
    maxd = max(lantern[i + 1] - lantern[i], maxd);
  }
  cout << setprecision(8);
  cout << fixed;
  long double solve = static_cast<long double>(maxd) / 2;
  cout << solve << endl;
}