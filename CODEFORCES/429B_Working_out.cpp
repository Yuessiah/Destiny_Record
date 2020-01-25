#include<bits/stdc++.h>
using namespace std;

int const maxn = 1e3 + 10;

int n, m, a[maxn][maxn];
/* L := left, R := right, T := top, B := bottom, mt := meeting */
int LT_mt[maxn][maxn], RB_mt[maxn][maxn], LB_mt[maxn][maxn], RT_mt[maxn][maxn];

int main()
{
  scanf("%d%d", &n, &m);

  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++) scanf("%d", &a[i][j]);


  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++) LT_mt[i][j] = a[i][j] + max(LT_mt[i-1][j], LT_mt[i][j-1]);

  for(int i = n; i >= 1; i--)
    for(int j = m; j >= 1; j--) RB_mt[i][j] = a[i][j] + max(RB_mt[i+1][j], RB_mt[i][j+1]);

  for(int i = n; i >= 1; i--)
    for(int j = 1; j <= m; j++) LB_mt[i][j] = a[i][j] + max(LB_mt[i+1][j], LB_mt[i][j-1]);

  for(int i = 1; i <= n; i++)
    for(int j = m; j >= 1; j--) RT_mt[i][j] = a[i][j] + max(RT_mt[i-1][j], RT_mt[i][j+1]);


  int best = 0;
  for(int i = 2; i < n; i++)
    for(int j = 2; j < m; j++)
      best = max({best, LT_mt[i-1][j]+RB_mt[i+1][j] + LB_mt[i][j-1]+RT_mt[i][j+1],
                        LT_mt[i][j-1]+RB_mt[i][j+1] + LB_mt[i+1][j]+RT_mt[i-1][j]});

  printf("%d\n", best);

  return 0;
}
