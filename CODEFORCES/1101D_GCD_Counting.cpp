#include<bits/stdc++.h>
using namespace std;

int constexpr maxn = 2e5 + 10, lgmaxn = 18;

int n, a[maxn], ans = 1, dp[maxn][lgmaxn];
vector<int> E[maxn], fac[maxn];

void dfs(int u, int p) {
  fill(dp[u], dp[u]+lgmaxn, 1);

  for(int v: E[u]) {
    if(v == p) continue;
    dfs(v, u);

    for(int i = 0, j = 0; i < fac[a[u]].size(); i++) {
      while(j < fac[a[v]].size() && fac[a[v]][j] < fac[a[u]][i]) j++;
      if(j == fac[a[v]].size() || fac[a[v]][j] != fac[a[u]][i]) continue;

      ans = max(ans, dp[u][i] + dp[v][j]);
      dp[u][i] = max(dp[u][i], 1 + dp[v][j]);
    }
  }
}


int main()
{
  for(int i = 2; i < maxn; i++) {
    if(fac[i].size() > 0) continue;
    for(int j = i; j < maxn; j+=i) fac[j].push_back(i);
  }


  cin >> n;

  bool ok = false;
  for(int u = 1; u <= n; u++) {
    cin >> a[u];
    if(a[u] > 1) ok = true;
  }

  while(--n) {
    int x, y;
    cin >> x >> y;
    E[x].push_back(y);
    E[y].push_back(x);
  }

  if(!ok) cout << 0 << endl;
  else {
    dfs(1, 1);
    cout << ans << endl;
  }

  return 0;
}
