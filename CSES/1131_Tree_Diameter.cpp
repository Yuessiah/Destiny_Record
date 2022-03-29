#include<bits/stdc++.h>
using namespace std;

int constexpr maxn = 2e5 + 10;

int n, a, b, ans, dp[maxn];
vector<int> E[maxn];

void dfs(int u, int p) {
  for(int v: E[u]) {
    if(v == p) continue;

    dfs(v, u);
    ans = max(ans, dp[u] + 1 + dp[v]);
    dp[u] = max(dp[u], 1 + dp[v]);
  }
}

int main()
{
  cin >> n;
  while(--n) {
    cin >> a >> b;
    E[a].push_back(b);
    E[b].push_back(a);
  }

  dfs(1, 1);
  cout << ans << endl;

  return 0;
}
