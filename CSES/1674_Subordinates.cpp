#include<bits/stdc++.h>
using namespace std;

int constexpr maxn = 2e5 + 10;

int n, sub[maxn];
vector<int> E[maxn];

void dfs(int u) {
  for(int v: E[u]) {
    dfs(v);
    sub[u] += sub[v];
  }

  sub[u] += 1;
}

int main()
{
  cin >> n;
  for(int i = 2, boss; i <= n; i++) {
    cin >> boss;
    E[boss].push_back(i);
  }

  dfs(1);
  for(int i = 1; i <= n; i++) cout << --sub[i] << ' ';
  cout << endl;
}
