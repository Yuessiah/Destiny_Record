#include<bits/stdc++.h>
using namespace std;

int const maxn = 2e5 + 10;

int n, m, k, x, y;
vector<int> E[maxn], a;

void bfs(int s, vector<int> &d) {
  queue<int> q;
  set<int> vis;
  q.push(s);
  vis.insert(s);
  d[s] = 0;
  while(q.size()) {
    int u = q.front(); q.pop();
    for(int v: E[u]) {
      if(vis.count(v)) continue;
      vis.insert(v);
      d[v] = d[u] + 1;
      q.push(v);
    }
  }
}

int main()
{
  scanf("%d%d%d", &n, &m, &k);

  a.resize(k);
  for(int i = 0; i < k; i++) scanf("%d", &a[i]);
  for(int i = 0; i < m; i++) {
    scanf("%d%d", &x, &y);
    E[x].push_back(y);
    E[y].push_back(x);
  }

  vector<int> d1(n+1), dn(n+1);
  bfs(1, d1);
  bfs(n, dn);

  sort(a.begin(), a.end(), [&](int x, int y) { return d1[x] < d1[y]; });

  int ans = 0;
  for(int i = 0; i+1 < k; i++) ans = max(ans, d1[a[i]] + 1 + dn[a[i+1]]);

  printf("%d\n", min(ans, d1[n]));

  return 0;
}
