#include<bits/stdc++.h>
using namespace std;

int constexpr maxn = 2e5 + 10;

int n, a, b, ans[maxn];
vector<int> E[maxn];

pair<int, int> dfs(int u, int p, int d) {
  ans[u] = max(ans[u], d);

  pair<int, int> res {d, u};
  for(int v: E[u]) {
    if(v == p) continue;
    res = max(res, dfs(v, u, d+1));
  }

  return res;
}

int main()
{
  cin >> n;
  for(int i = 0; i < n-1; i++) {
    cin >> a >> b;
    E[a].push_back(b);
    E[b].push_back(a);
  }

  dfs(dfs(dfs(1, -1, 0).second, -1, 0).second, -1, 0);
  for(int v = 1; v <= n; v++) cout << ans[v] << ' ';
  cout << endl;

  return 0;
}
