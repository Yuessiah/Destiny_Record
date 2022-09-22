#include<bits/stdc++.h>
using namespace std;

typedef long long Int;

int constexpr maxN = 2e5 + 10, MOD = 998244353;

int N, dep1[maxN], dep2[maxN];
vector<int> E[maxN];

pair<int, int> dfs1(int u, int p) {
  dep1[u] = dep1[p] + 1;

  pair<int, int> res {dep1[u], u};
  for(int v: E[u]) {
    if(v == p) continue;
    res = max(res, dfs1(v, u));
  }

  return res;
}

pair<int, int> dfs2(int u, int p) {
  dep2[u] = dep2[p] + 1;

  pair<int, int> res {dep2[u], u};
  for(int v: E[u]) {
    if(v == p) continue;
    res = max(res, dfs2(v, u));
  }

  return res;
}

int find_dis(int u, int p, int dis, int d) {
  int res = d==dis;

  for(int v: E[u]) {
    if(v == p) continue;
    res += find_dis(v, u, dis, d+1);
  }

  return res;
}


int main()
{
  cin >> N;
  for(int i = 0; i < N-1; i++) {
    int U, V;
    cin >> U >> V;
    E[U].push_back(V);
    E[V].push_back(U);
  }

  int lhs_rt = dfs1(1, 1).second;

  dep1[lhs_rt] = -1;
  int rhs_rt = dfs1(lhs_rt, lhs_rt).second;

  dep2[rhs_rt] = -1;
  int dim = dfs2(rhs_rt, rhs_rt).first;

  if(dim&1) {
    Int lhs = 0, rhs = 0; // number of two sides
    for(int u = 1; u <= N; u++) lhs += dep2[u]==dim;
    for(int u = 1; u <= N; u++) rhs += dep1[u]==dim;

    cout << lhs*rhs % MOD << endl;
  } else {
    int center;
    for(int u = 1; u <= N; u++)
      if(dep1[u] == dim/2 && dep2[u] == dim/2) center = u;

    Int sum = 0, ans = 1;
    for(int v: E[center]) {
      sum += find_dis(v, center, dim/2, 1);
      ans = ans * (1 + find_dis(v, center, dim/2, 1)) % MOD;
    }
    cout << (ans -= sum + 1) << endl;
  }

  return 0;
}
