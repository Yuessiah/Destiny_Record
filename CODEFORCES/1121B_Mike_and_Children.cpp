#include<bits/stdc++.h>
using namespace std;

int const maxn = 1e5 + 10;

int n, a[maxn], c[2*maxn];

int main()
{
  scanf("%d", &n);
  for(int i = 0; i < n; i++) scanf("%d", &a[i]);

  for(int i = 0; i < n; i++)
    for(int j = i+1; j < n; j++) c[a[i]+a[j]]++;

  int ans = 0;
  for(int i = 0; i < maxn*2; i++) ans = max(ans, c[i]);

  printf("%d\n", ans);

  return 0;
}
