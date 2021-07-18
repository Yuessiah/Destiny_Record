#include<bits/stdc++.h>
using namespace std;

int constexpr maxn = 1e6 + 10;
int constexpr MOD = 1000000007;

int t, n;
long long dp[maxn][2];

int main()
{
  dp[1][0] = dp[1][1] = 1;
  for(n = 2; n < maxn; n++) {
    dp[n][0] = (4*dp[n-1][0] + dp[n-1][1]) % MOD;
    dp[n][1] = (2*dp[n-1][1] + dp[n-1][0]) % MOD;
  }

  cin >> t;
  while(t--) {
    cin >> n;
    cout << (dp[n][0] + dp[n][1]) % MOD << endl;
  }

  return 0;
}
