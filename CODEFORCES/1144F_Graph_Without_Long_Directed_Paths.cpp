#include<bits/stdc++.h>
using namespace std;

int const maxn = 2e5 + 10;

int n, m, d[maxn], u[maxn], v[maxn];
bool vis[maxn], ok;
vector<int> E[maxn];

void dfs(int u) {
  for(auto v: E[u]) {
    if(d[v] != -1 && !d[v] != d[u]) ok = false;

    if(vis[v]) continue;
    vis[v] = true;

    d[v] = !d[u];
    dfs(v);
  }
}

int main()
{
  scanf("%d%d", &n, &m);

  for(int i = 0; i < m; i++) {
    scanf("%d%d", &u[i], &v[i]);
    E[u[i]].push_back(v[i]);
    E[v[i]].push_back(u[i]);
  }

  memset(vis, false, sizeof vis);
  memset(d, -1, sizeof d);
  dfs(ok = vis[1] = d[1] = 1);

  if(ok) {
    puts("YES");
    for(int i = 0; i < m; i++) printf("%d", d[u[i]]);
    putchar('\n');
  } else puts("NO");

  return 0;
}
