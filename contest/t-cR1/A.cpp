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
    ll max = 0;
    cin >> n;
    vector<ll> whiteboard;
    for (auto i = 0; i < 2 * n; i++)
    {
      ll tmp;
      cin >> tmp;
      whiteboard.push_back(tmp);
    }

    sort(whiteboard.begin(), whiteboard.end());

    for (auto i = 1; i <= n; ++i)
    {
      max += whiteboard[(i - 1) * 2];
    }
    cout << max << endl;
  }
  return 0;
}