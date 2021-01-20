#include<bits/stdc++.h>
using namespace std;

int const MOD = 1000000007;
int const maxn = 1e5 + 10;
int const maxm = 110;

int n, m, x, dp[maxn][maxm];

int main()
{
  cin >> n >> m;

  memset(dp, 0, sizeof dp);
  for(int i = 0; i < n; i++) {
    cin >> x;

    auto addprev = [](int i, int v) {
      int res = 0;
      (res += dp[i-1][v-1]) %= MOD;
      (res += dp[i-1][ v ]) %= MOD;
      (res += dp[i-1][v+1]) %= MOD;
      return res;
    };

    if(x) dp[i][x] = i? addprev(i, x) : 1;
    else for(int v = 1; v <= m; v++) dp[i][v] = i? addprev(i, v) : 1;
  }

  int sum = 0;
  for(int v = 1; v <= m; v++) sum = (sum + dp[n-1][v]) % MOD;
  cout << sum << endl;

  return 0;
}
