#include<bits/stdc++.h>
using namespace std;

typedef long long Int;

int constexpr maxn = 1e5 + 10, MOD = 1000000007;

int n, p, x[maxn];
Int dp[maxn][2];
vector<int> E[maxn];

void dfs(int u) {
  dp[u][x[u]] = 1;

  for(int v: E[u]) {
    dfs(v);

    Int t1 = dp[u][1] * (dp[v][0] + dp[v][1]) + dp[u][0] * dp[v][1];
    Int t0 = dp[u][0] * (dp[v][0] + dp[v][1]);

    dp[u][1] = t1 % MOD;
    dp[u][0] = t0 % MOD;
  }
}


int main()
{
  cin >> n;
  for(int i = 0; i < n-1; i++) {
    cin >> p;
    E[p].push_back(i+1);
  }

  for(int i = 0; i < n; i++) cin >> x[i];

  dfs(0);
  cout << dp[0][1] << endl;

  return 0;
}
