#include<bits/stdc++.h>
using namespace std;

int const maxn = 2e5 + 10;

int t, n, m, a[maxn];

int main()
{
  scanf("%d", &t);

  while(t--) {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);

    vector<int> mx(n+1, 0);

    scanf("%d", &m);
    for(int i = 0; i < m; i++) {
      int p, s;
      scanf("%d%d", &p, &s);
      mx[s] = max(mx[s], p);
    }
    for(int s = n-1; s >= 1; s--) mx[s] = max(mx[s], mx[s+1]);

    int day = 0, i = 1;
    while(1) {
      int s = 1, mx_a = 0;
      while(i <= n && mx[s] >= (mx_a = max(mx_a, a[i]))) s++, i++;
      day++;

      if(i > n || s == 1) break;
    }

    printf("%d\n", i<=n? -1 : day);
  }

  return 0;
}
