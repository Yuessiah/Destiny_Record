#include<bits/stdc++.h>
using namespace std;

int const maxn = 1e5 + 10;

int n, m, b[maxn], g[maxn];

int main()
{
  scanf("%d%d", &n, &m);
  for(int i = 0; i < n; i++) scanf("%d", &b[i]);
  for(int i = 0; i < m; i++) scanf("%d", &g[i]);

  sort(b, b+n);
  sort(g, g+m);

  if(b[n-1] > g[0]) { puts("-1"); return 0; }

  long long sum = 0;
  for(int i = 0; i < m; i++) sum += g[i];
  for(int i = 0; i < n-1; i++) sum += (long long)m * b[i];

  if(b[n-1] != g[0]) sum += b[n-1] - b[n-2];

  printf("%lld\n", sum);

  return 0;
}
