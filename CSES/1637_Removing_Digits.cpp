#include<bits/stdc++.h>
using namespace std;

int const maxn = 1e6 + 10;

int n, dp[maxn];

int main()
{
  cin >> n;

  memset(dp, 0x3f, sizeof dp);
  dp[0] = 0;
  for(int k = 0; k <= n; k++)
    for(int x = k; x; x/=10) {
      int d = x%10;
      dp[k] = min(dp[k], dp[k-d]+1);
    }

  cout << dp[n] << endl;

  return 0;
}
