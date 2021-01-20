#include<bits/stdc++.h>
using namespace std;

int const maxa = 510;

int a, b, dp[maxa][maxa];

int main()
{
  cin >> a >> b;

  memset(dp, 0x3f, sizeof dp);
  for(int i = 1; i <= max(a, b); i++) dp[i][i] = 0;

  for(int i = 1; i <= a; i++)
    for(int j = 1; j <= b; j++) {
      for(int k = 1; k < i; k++) dp[i][j] = min(dp[i][j], dp[k][j] + dp[i-k][j] + 1);
      for(int k = 1; k < j; k++) dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j-k] + 1);
    }

  cout << dp[a][b] << endl;

  return 0;
}
