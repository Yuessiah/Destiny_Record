#include<bits/stdc++.h>
using namespace std;

int n, m;

int main()
{
  scanf("%d%d", &n, &m);

  vector<int> a(n), b(n), c(n);
  for(int i = 0; i < n; i++) scanf("%d", &a[i]);
  for(int i = 0; i < n; i++) scanf("%d", &b[i]);

  int ans = m;
  sort(b.begin(), b.end());
  for(int i = 0; i < n; i++) {
    int x = (b[i]-a[0]+m) % m;
    for(int j = 0; j < n; j++) c[j] = (a[j]+x) % m;

    sort(c.begin(), c.end());
    if(b == c) ans = min(ans, x);
  }

  printf("%d\n", ans);

  return 0;
}
