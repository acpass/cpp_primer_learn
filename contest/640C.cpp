#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve()
{
  ll n, k;
  cin >> n >> k;

  ll i = 1;

  while (1)
  {
    if (i % n != 0)
      k--;

    if (!k)
      break;
    else
      i++;
  }

  cout << i << '\n';
}

int main()
{
  ll n;
  cin >> n;

  while (n--)
  {
    solve();
  }
  cout << endl;
}