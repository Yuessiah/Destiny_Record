#include<bits/stdc++.h>
using namespace std;

int const maxn = 2e5 + 10;

int n, m, gp[maxn], mx[maxn]; // gp := group, mx := maximum of group

int Find(int v) {
  if(v == gp[v]) return v;

  int ld = Find(gp[v]); // ld := leader
  mx[ld] = max(mx[ld], mx[v]);
  return gp[v] = ld;
}

void Union(int u, int v) {
  int a = Find(u), b = Find(v);
  gp[a] = b;
  mx[a] = mx[b] = max(mx[a], mx[b]);
}

int main()
{
  scanf("%d%d", &n, &m);
  for(int v = 1; v <= n; v++) gp[v] = mx[v] = v;

  for(int i = 0; i < m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    Union(u, v);
  }

  int cnt = 0;
  for(int u = 1, v; u <= n; u=v)
    for(v = u+1; v <= mx[Find(u)]; v++) {
      if(Find(u) == Find(v)) continue;
      Union(u, v);
      cnt++;
    }

  printf("%d\n", cnt);

  return 0;
}
