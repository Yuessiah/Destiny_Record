#include<bits/stdc++.h>
using namespace std;

int const maxn = 110;

int q, n, m, t[maxn], l[maxn], h[maxn];

int main()
{
  scanf("%d", &q);

  while(q--) {
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++) scanf("%d%d%d", &t[i], &l[i], &h[i]);

    bool ok = true;
    int pre = 0, mi = m, mx = m; // min, max
    for(int i = 0; i < n; i++) {
      mi -= t[i] - pre;
      mx += t[i] - pre;
      if(h[i] < mi || l[i] > mx) ok = false;

      mi = max(mi, l[i]);
      mx = min(mx, h[i]);
      pre = t[i];
    }

    puts(ok? "YES" : "NO");
  }

  return 0;
}
