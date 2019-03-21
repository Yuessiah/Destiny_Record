#include<bits/stdc++.h>
using namespace std;

int const maxn = 2e5 + 10;

int n, q;
long long p[maxn];
map<long long, bool> vis;

int main()
{
  scanf("%d", &n);

  long long error = p[0] = 1;
  for(int i = 1; i < n; i++) {
    scanf("%d", &q);
    error = min(error, p[i] = p[i-1] + q);
  }

  for(int i = 0; i < n; i++) {
    p[i] -= error - 1;
    if(p[i] > n || vis[p[i]]) { puts("-1"); return 0; }
    vis[p[i]] = true;
  }

  for(int i = 0; i < n; i++) printf("%lld ", p[i]);

  return 0;
}
