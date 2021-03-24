#include<bits/stdc++.h>
using namespace std;
typedef long long Int;

int constexpr maxn = 3e5 + 10;

int n, x;
Int a[maxn];

int main()
{
  cin >> n >> x;

  Int dp[3] {}, best = 0;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    dp[2] = max({dp[1] + 1*a[i], dp[2] + 1*a[i], 1*a[i]});
    dp[1] = max({dp[0] + x*a[i], dp[1] + x*a[i], x*a[i]});
    dp[0] = max({dp[0] + 1*a[i], 1*a[i]});

    best = max({best, dp[0], dp[1], dp[2]});
  }

  cout << best << endl;

  return 0;
}
