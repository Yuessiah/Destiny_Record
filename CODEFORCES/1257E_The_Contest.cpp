#include<bits/stdc++.h>
using namespace std;

int const maxn = 2e5 + 10;

int k[3], p[maxn];

int main()
{
  scanf("%d%d%d", &k[0], &k[1], &k[2]);

  int a, n = 0;
  for(int i = 0; i < 3; i++) {
    n += k[i];
    for(int j = 0; j < k[i]; j++) {
      scanf("%d", &a);
      p[a] = i;
    }
  }

  int pre[3][maxn] = {};
  for(int i = 0; i < 3; i++)
    for(int j = 1; j <= n; j++)
      pre[i][j] = pre[i][j-1] + (p[j]!=i);

  int move = n;
  for(int r = 0, l = 0; r <= n; r++) {
    int x = pre[0][l] + (pre[1][r]-pre[1][l]) + (pre[2][n]-pre[2][r]);
    int y = pre[0][r] + (pre[1][r]-pre[1][r]) + (pre[2][n]-pre[2][r]);

    if(y < x) l = r, move = min(move, y);
    else move = min(move, x);
  }

  printf("%d\n", move);

  return 0;
}
