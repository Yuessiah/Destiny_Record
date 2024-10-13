#include<bits/stdc++.h>
using namespace std;

const int maxn = 2e3 + 10;

int n, a[maxn];
long long dp[maxn][maxn], INF = 2e12;

int main()
{
  cin >> n;
  for(int i = 1; i <= n; i++) cin >> a[i];

  for(int i = 0; i <= n; i++)
    for(int j = 1; j <= n; j++) dp[i][j] = -INF;

  for(int j = 1; j <= n; j++)
    for(int i = 1; i <= n; i++) {
      dp[i][j] = max(dp[i-1][j], dp[i-1][j-1] + a[i]);
      if(dp[i][j] < 0) dp[i][j] = -INF;
    }

  for(int j = n; j >= 0; j--) {
    if(dp[n][j] < 0) continue;
    cout << j << endl;
    break;
  }

  return 0;
}
