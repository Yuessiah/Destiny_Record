#include<bits/stdc++.h>
using namespace std;

int constexpr maxn = 1e5 + 10;

int n, ans[2], dp[maxn][2];
vector<pair<int, int>> E[maxn];

void update(int x[], int a, int b, int c) {
  int t[] {x[0], x[1], a, b, c};
  sort(t, t+5), reverse(t, t+5), unique(t, t+5);
  x[0] = t[0], x[1] = t[1];
}

void dfs(int u, int p) {
  for(auto [v, w]: E[u]) {
    if(v == p) continue;
    dfs(v, u);

    update(ans,
           dp[u][0] + w + dp[v][0],
           dp[u][0] + w + dp[v][1],
           dp[u][1] + w + dp[v][0]);

    update(dp[u],
           w + dp[v][0],
           w + dp[v][0],
           w + dp[v][1]);
  }
}

int main()
{
  cin >> n;
  while(--n) {
    int u, v, w;
    cin >> u >> v >> w;
    E[u].emplace_back(v, w);
    E[v].emplace_back(u, w);
  }

  dfs(0, -1);
  cout << ans[1] << endl;

  return 0;
}
