#include<bits/stdc++.h>
using namespace std;

int const maxn = 60;
int const dr[] = {0, 0, -1, 1};
int const dc[] = {-1, 1, 0, 0};

struct coordinate { int r, c; };
typedef vector<coordinate> Region;

int n, r1, r2, c1, c2;
char flat[maxn][maxn];
bool vis[maxn][maxn];
Region land1, land2;

int dis(coordinate p, coordinate q) {
  int r = p.r - q.r, c = p.c - q.c;
  return r*r + c*c;
}

void dfs(int r, int c, Region &land) {
  land.push_back((coordinate){r, c});
  vis[r][c] = true;

  for(int d = 0; d < 4; d++) {
    int nr = r+dr[d], nc = c+dc[d];

    if(nr <= 0 || nc <= 0 || nr > n || nc > n
        || vis[nr][nc] || flat[nr][nc] == '1') continue;

    dfs(nr, nc, land);
  }
}

int main()
{
  scanf("%d", &n);
  scanf("%d%d%d%d", &r1, &c1, &r2, &c2);

  for(int r = 1; r <= n; r++)
    for(int c = 1; c <= n; c++) scanf(" %c", &flat[r][c]);

  memset(vis, false, sizeof vis);
  dfs(r1, c1, land1);

  memset(vis, false, sizeof vis);
  dfs(r2, c2, land2);

  int cost = maxn*maxn*2;
  for(int i = 0; i < land1.size(); i++)
    for(int j = 0; j < land2.size(); j++)
      cost = min(cost, dis(land1[i], land2[j]));

  printf("%d\n", cost);

  return 0;
}
