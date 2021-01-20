#include<bits/stdc++.h>
using namespace std;

int const MOD = 1000000007;
int const maxx = 1e6 + 10;
int const maxn = 101;

int n, x, c[maxn], dp[maxx];

int main()
{
  cin >> n >> x;
  for(int i = 0; i < n; i++) cin >> c[i];

  dp[0] = 1;
  for(int i = 0; i < n; i++)
    for(int k = c[i]; k <= x; k++)
      dp[k] = (dp[k] + dp[k-c[i]]) % MOD;

  cout << dp[x] << endl;

  return 0;
}
