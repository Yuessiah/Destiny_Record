#include<bits/stdc++.h>
using namespace std;

int const maxm = 25, maxd = 1e5;

int m, d[maxm], ans, vis[2*maxm*maxd+1];

void dfs(int i, int pos, int cnt) {
  if(i == m) {
    ans = min(ans, cnt);
    return;
  }

  vis[pos]++;
  dfs(i+1, pos+d[i], cnt + !vis[pos+d[i]]);
  dfs(i+1, pos-d[i], cnt + !vis[pos-d[i]]);
  vis[pos]--;
}

int main()
{
  scanf("%d", &m);
  for(int i = 0; i < m; i++) scanf("%d", &d[i]);

  ans = m + 1;
  dfs(0, maxm*maxd, 1);

  printf("%d\n", ans);

  return 0;
}
