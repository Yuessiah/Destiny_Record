#include<bits/stdc++.h>
using namespace std;

int const maxn = 101;
int const maxx = 1e6 + 10;
int const INF = 0x3f3f3f3f;

int n, x, c[maxn], dp[maxx];

int main()
{
  cin >> n >> x;
  for(int i = 0; i < n; i++) cin >> c[i];

  memset(dp, 0x3f, sizeof dp);
  dp[0] = 0;
  for(int k = 1; k <= x; k++) {
    for(int i = 0; i < n; i++)
      if(k-c[i] >= 0) dp[k] = min(dp[k], dp[k-c[i]]+1);
  }

  if(dp[x] == INF) dp[x] = -1;
  cout << dp[x] << endl;

  return 0;
}
