#include<bits/stdc++.h>
using namespace std;

int const maxn = 5010;

string s1, s2;
int dp[maxn][maxn];

int main()
{
  cin >> s1 >> s2;
  int n = s1.length(), m = s2.length();

  s1 = '^' + s1; // align length and index
  s2 = '^' + s2;

  memset(dp, 0x3f, sizeof dp);
  dp[0][0] = 0; // both length is 0

  for(int i = 0; i <= n; i++)
    for(int j = 0; j <= m; j++) {
      dp[i+1][ j ] = min(dp[i+1][ j ], 1 + dp[i][j]);
      dp[ i ][j+1] = min(dp[ i ][j+1], 1 + dp[i][j]);
      dp[i+1][j+1] = min(dp[i+1][j+1], (s1[i+1] != s2[j+1]) + dp[i][j]);
    }

  cout << dp[n][m] << endl;

  return 0;
}
