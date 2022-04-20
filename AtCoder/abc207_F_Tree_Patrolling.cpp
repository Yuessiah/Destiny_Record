#include<bits/stdc++.h>
typedef long long Int;

using namespace std;

int constexpr maxN = 2010, MOD = 1000000007;

int N, sz[maxN];
Int dp[maxN][maxN][3];
vector<int> E[maxN];

void dfs(int u, int p) {
  sz[u] = 1;
  dp[u][0][2] = dp[u][1][0] = 1;

  for(int v: E[u]) {
    if(v == p) continue;
    dfs(v, u);

    Int tmp[maxN][3] {};
    for(int x = 0; x <= sz[u]; x++) {
      for(int y = 0; y <= sz[v]; y++) {
        tmp[x+y][0] += dp[u][x][0]*(dp[v][y][0] + dp[v][y][1] + (y? dp[v][y-1][2] : 0));
        tmp[x+y][1] += dp[u][x][1]*(dp[v][y][0] + dp[v][y][1] + dp[v][y][2]) + (x? dp[u][x-1][2]*dp[v][y][0] : 0);
        tmp[x+y][2] += dp[u][x][2]*(dp[v][y][1] + dp[v][y][2]);

        tmp[x+y][0] %= MOD;
        tmp[x+y][1] %= MOD;
        tmp[x+y][2] %= MOD;
      }
    }

    memcpy(dp[u], tmp, sizeof(tmp));
    sz[u] += sz[v];
  }
}

int main()
{
  cin >> N;

  for(int i = 0; i < N-1; i++) {
    int u, v;
    cin >> u >> v;
    E[u].push_back(v);
    E[v].push_back(u);
  }

  dfs(1, 1);
  for(int k = 0; k <= N; k++)
    cout << (dp[1][k][0] + dp[1][k][1] + dp[1][k][2]) % MOD << endl;

  return 0;
}
