#include<stdio.h>
#include<string.h>
const int maxn = 100 + 10;

int m, n;
char plot[maxn][maxn];

void dfs(int r, int c)
{
  if(plot[r][c] == '*') return;
  plot[r][c] = '*';

  for(int dr = -1; dr <= 1; dr++)
    for(int dc = -1; dc <= 1; dc++)
      if(r+dr >= 0 && r+dr < m && c+dc >= 0 && c+dc < n)
        dfs(r+dr, c+dc);
}

int main()
{
  while(scanf("%d%d", &m, &n) == 2 && m) {
    for(int i = 0; i < m; i++) scanf("%s", plot[i]);

    int cnt = 0;
    for(int i = 0; i < m; i++)
      for(int j = 0; j < n; j++)
        if(plot[i][j] == '@') {
          dfs(i, j);
          cnt++;
        }

    printf("%d\n", cnt);
  }

  return 0;
}
