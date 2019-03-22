#include<bits/stdc++.h>
using namespace std;

int const MOD = 1000000007;
int const maxn = 2e5 + 10;

int n, k, group[maxn];
map<int, int> cnt;

int Find(int u) { return (group[u] == u)? u : group[u] = Find(group[u]); }
void Union(int u, int v) { group[Find(u)] = Find(v); }

int mpow(int p) {
  long long pro = 1;
  for(int i = 0; i < k; i++) pro = (pro * p)%MOD;
  return pro;
}

int main()
{
  scanf("%d%d", &n, &k);

  for(int i = 1; i <= n; i++) group[i] = i;

  int u, v, x;
  for(int i = 0; i < n-1; i++) {
    scanf("%d%d%d", &u, &v, &x);
    if(x) continue;
    Union(u, v);
  }

  int sum = mpow(n);
  for(int i = 1; i <= n; i++) ++cnt[Find(i)];
  for(auto& it: cnt) {
    sum -= mpow(it.second);
    if(sum < 0) sum += MOD;
  }

  printf("%d\n", sum);

  return 0;
}
