#include<bits/stdc++.h>
using namespace std;

int constexpr maxn = 1e6 + 10;

int n, a;
long long dp[maxn][3];

int main()
{
  cin >> n;

  memset(dp, -0x3f, sizeof dp);
  dp[0][2] = 0;

  for(int i = 1; i <= n; i++) {
    cin >> a;
    dp[i][2] = max({dp[i-1][2], dp[i-1][1] - a, dp[i-1][0] + a});
    dp[i][1] = max(dp[i-1][1], dp[i-1][2] + a);
    dp[i][0] = max(dp[i-1][0], dp[i-1][2] - a);
  }

  cout << dp[n][2] << endl;

  return 0;
}
