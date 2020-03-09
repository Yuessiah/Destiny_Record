#include<bits/stdc++.h>
using namespace std;

int const maxn = 2e5 + 10;

int n, m, k, a, x, y;
vector<int> E[maxn], ord;
vector<bool> sp;

void bfs(int s, vector<int> &d) {
  queue<int> q;
  q.push(s);
  d.assign(n+1, -1);
  d[s] = 0;

  while(q.size()) {
    int u = q.front(); q.pop();
    if(s == 1 && sp[u]) ord.push_back(u);

    for(int v: E[u]) {
      if(d[v] != -1) continue;
      d[v] = d[u] + 1;
      q.push(v);
    }
  }
}

int main()
{
  scanf("%d%d%d", &n, &m, &k);

  sp.assign(n+1, false);
  for(int i = 0; i < k; i++) scanf("%d", &a), sp[a] = true;
  for(int i = 0; i < m; i++) {
    scanf("%d%d", &x, &y);
    E[x].push_back(y);
    E[y].push_back(x);
  }

  vector<int> d1, dn;
  bfs(1, d1);
  bfs(n, dn);

  int ans = 0, d1_mx = 0;
  for(int i = 0; i+1 < ord.size(); i++) {
    d1_mx = max(d1_mx, d1[ord[i]]);
    ans = max(ans, d1_mx + 1 + dn[ord[i+1]]);
  }

  printf("%d\n", min(ans, d1[n]));

  return 0;
}
