#include<bits/stdc++.h>
using namespace std;

int const MOD = 1000000007;
int const maxn = 1e3 + 10;

int n, dp[maxn][maxn];
char gd;

int main()
{
  cin >> n;

  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++) {
      cin >> gd;
      if(gd == '*') continue;
      if(!i && !j) dp[0][0] = 1;

      if(i) dp[i][j] = (dp[i][j] + dp[i-1][j]) % MOD;
      if(j) dp[i][j] = (dp[i][j] + dp[i][j-1]) % MOD;
    }

  cout << dp[n-1][n-1] << endl;

  return 0;
}
