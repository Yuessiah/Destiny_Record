#include<bits/stdc++.h>
using namespace std;
typedef long long Int;

int const maxn = 5e3 + 10;

int n, x[maxn];
Int dp[maxn][maxn];

int main()
{
  cin >> n;

  Int s[maxn] = {0};
  for(int i = 1; i <= n; i++) {
    cin >> x[i];
    s[i] = s[i-1] + x[i];
  }

  memset(dp, 0, sizeof dp);
  for(int i = 1; i <= n; i++) dp[i][i] = x[i];

  for(int l = 1; l < n; l++)
    for(int i = 1; i+l <= n; i++) {
      Int left = x[i] + s[i+l]-s[i]-dp[i+1][i+l];
      Int right = x[i+l] + s[i+l-1]-s[i-1]-dp[i][i+l-1];
      dp[i][i+l] = max(left, right);
    }

  cout << dp[1][n] << endl;

  return 0;
}
