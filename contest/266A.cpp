#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
  ll n, m, a, b;
  cin >> n >> m >> a >> b;

  ll price = 0;

  if (a <= b / m)
    price += a * n;
  else
  {
    price += n / m * b;
    n %= m;
    price += min(n * a, b);
  }

  cout << price << endl;
}