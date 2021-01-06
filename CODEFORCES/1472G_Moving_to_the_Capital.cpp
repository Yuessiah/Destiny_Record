#include<bits/stdc++.h>
using namespace std;

int const maxn = 2e5 + 10;

int t, n, m, d[maxn];
vector<int> g[maxn];

int main()
{
  cin >> t;
  while(t--) {
    cin >> n >> m;
    for(int u = 1; u <= n; u++) g[u].clear();

    for(int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      g[u].push_back(v);
    }

    vector<int> ans(n+1);
    queue<int> q;
    q.push(1);
    memset(d, -1, sizeof d);
    ans[1] = d[1] = 0;

    while(q.size()) {
      int u = q.front(); q.pop();
      for(int v: g[u]) {
        if(d[v] != -1) continue;
        ans[v] = d[v] = d[u] + 1;
        q.push(v);
      }
    }

    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 1);
    sort(ord.begin(), ord.end(), [](int a, int b) { return d[a] > d[b]; });
    for(int u: ord)
      for(int v: g[u]) {
        if(d[u] < d[v])
          ans[u] = min(ans[u], ans[v]);
        else
          ans[u] = min(ans[u], d[v]);
      }

    for(int u = 1; u <= n; u++) cout << ans[u] << ' ';
    cout << endl;
  }

  return 0;
}
