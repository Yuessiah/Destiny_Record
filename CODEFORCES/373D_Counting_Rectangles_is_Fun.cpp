#include<bits/stdc++.h>
using namespace std;

int constexpr maxn = 50;

int n, m, q, a, b, c, d;
char grid[maxn][maxn];
int pre[maxn][maxn], dp[maxn][maxn][maxn][maxn];

int main()
{
  cin >> n >> m >> q;

  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++)
      cin >> grid[i][j];

  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++)
      pre[i][j] = pre[i][j-1]+pre[i-1][j]-pre[i-1][j-1]+(grid[i][j]=='1');

  for(int a = n; a >= 1; a--)
    for(int b = m; b >= 1; b--)
      for(int c = a; c <= n; c++)
        for(int d = b; d <= m; d++) {
          dp[a][b][c][d] = pre[c][d]-pre[c][b-1]-pre[a-1][d]+pre[a-1][b-1] == 0; // good?

          for(int k = 1; k < 1<<4; k++) {
            int pie = (__builtin_popcount(k)&1)? 1 : -1; // principle of inclusion-exclusion
            dp[a][b][c][d] += pie * dp[a+!!(k&1)][b+!!(k&2)][c-!!(k&4)][d-!!(k&8)];
          }
        }

  while(q--) {
    cin >> a >> b >> c >> d;
    cout << dp[a][b][c][d] << endl;
  }

  return 0;
}
