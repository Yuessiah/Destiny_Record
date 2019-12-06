#include<bits/stdc++.h>
using namespace std;

int const maxp = 10000, maxn = 15;

int t, n, p[maxn];

int main()
{
  scanf("%d", &t);

  while(t--) {
    scanf("%d", &n);

    int cnt = 0;
    bool tail[maxn] = {}, vis[maxp] = {}, unchg[maxn] = {};
    for(int i = 0; i < n; i++) {
      scanf("%d", &p[i]);

      if(!vis[p[i]]) {
        vis[p[i]] = unchg[i] = tail[p[i]%10] = true;
        cnt++;
      }
    }

    printf("%d\n", n - cnt);

    for(int i = 0; i < n; i++) {
      if(!unchg[i]) {
        for(int d = 0; d < 10; d++) if(!tail[d]) {
          p[i] = p[i]/10*10 + d;
          tail[d] = true;
          break;
        }
      }

      printf("%04d\n", p[i]);
    }
  }

  return 0;
}
