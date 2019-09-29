#include<bits/stdc++.h>
using namespace std;

int const MOD = 1000000007;
int const maxn = 1e3 + 10;

int h, w, r[maxn], c[maxn], grid[maxn][maxn];

int main()
{
  scanf("%d%d", &h, &w);
  for(int i = 0; i < h; i++) scanf("%d", &r[i]);
  for(int i = 0; i < w; i++) scanf("%d", &c[i]);

  memset(grid, 0, sizeof grid);

  for(int i = 0; i < h; i++) {
    for(int j = 0; j < r[i]; j++) grid[i][j] = 1;
    grid[i][r[i]] = 2;
  }

  for(int j = 0; j < w; j++) {
    for(int i = 0; i < c[j]; i++) {
      if(grid[i][j] == 2) {
        puts("0");
        return 0;
      }
      grid[i][j] = 1;
    }

    if(grid[c[j]][j] == 1) {
      puts("0");
      return 0;
    }
    grid[c[j]][j] = 2;
  }


  int ans = 1;
  for(int i = 0; i < h; i++)
    for(int j = 0; j < w; j++) if(!grid[i][j]) ans = (ans * 2) % MOD;

  printf("%d\n", ans);

  return 0;
}
