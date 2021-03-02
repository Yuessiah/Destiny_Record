#include<bits/stdc++.h>
using namespace std;

int t, n, k;
vector<vector<int>> g;
vector<bool> vis;

int dfs(int u) {
  if(g[u].size() == 1 && u != 1) return 0; // leaf

  vector<int> c;
  for(int v: g[u]) {
    if(vis[v]) continue;
    vis[v] = true;
    c.push_back(1 + dfs(v));
  }
  sort(c.begin(), c.end());

  if(c.size() >= 2) {
    if(u == 1) k = max({k, c.back(), *(c.rbegin()+1) + 1});
    else k = max(k, c.back() + 1);
  } else k = max(k, c.back());

  return c.front();
}

int main()
{
  cin >> t;
  while(t--) {
    cin >> n;

    g.assign(n+1, vector<int>());
    for(int i = 0; i < n-1; i++) {
      int u, v;
      cin >> u >> v;
      g[u].push_back(v);
      g[v].push_back(u);
    }

    vis.assign(n+1, false);
    vis[1] = true;
    k = 1;
    dfs(1);

    cout << k << endl;
  }

  return 0;
}
