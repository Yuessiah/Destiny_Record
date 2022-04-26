#include<bits/stdc++.h>
typedef long long Int;
using namespace std;

int constexpr maxN = 4e5 + 10;

int N, A, B, C, D;
Int dis[maxN];
vector<pair<int, int>> E[maxN];

pair<Int, int> dfs(int u, int p, Int d) {
  if(p != N+u) dis[u] = max(dis[u], d);

  pair<Int, int> res {d, u};
  for(auto [v, w]: E[u]) {
    if(v == p) continue;
    res = max(res, dfs(v, u, d+w));
  }

  return res;
}

int main()
{
  cin >> N;
  for(int i = 0; i < N-1; i++) {
    cin >> A >> B >> C;
    E[A].emplace_back(B, C);
    E[B].emplace_back(A, C);
  }

  for(int i = 1; i <= N; i++) {
    cin >> D;
    E[N+i].emplace_back(i, D);
    E[i].emplace_back(N+i, D);
  }


  dfs(dfs(dfs(1, -1, 0).second, -1, 0).second, -1, 0);
  for(int u = 1; u <= N; u++) cout << dis[u] << endl;

  return 0;
}
