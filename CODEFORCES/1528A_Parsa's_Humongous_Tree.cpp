#include<bits/stdc++.h>
using namespace std;

int constexpr maxn = 1e5 + 10;

int t, n, u, v, l[maxn], r[maxn];
long long dp[maxn][2];
vector<int> E[maxn];

void dfs(int u, int p) {
  for(int v: E[u]) {
    if(v == p) continue;

    dfs(v, u);
    dp[u][0] += max(dp[v][0] + abs(l[u]-l[v]), dp[v][1] + abs(l[u]-r[v]));
    dp[u][1] += max(dp[v][1] + abs(r[u]-r[v]), dp[v][0] + abs(r[u]-l[v]));
  }
}

int main()
{
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  cin >> t;
  while(t--) {
    cin >> n;

    // initialization
    for(int i = 1; i <= n; i++) {
      E[i].clear();
      dp[i][0] = dp[i][1] = 0;
    }

    for(int i = 1; i <= n; i++) cin >> l[i] >> r[i];
    for(int i = 0; i < n-1; i++) {
      cin >> u >> v;
      E[u].push_back(v);
      E[v].push_back(u);
    }

    dfs(1, 1);
    cout << max(dp[1][0], dp[1][1]) << endl;
  }

  return 0;
}
