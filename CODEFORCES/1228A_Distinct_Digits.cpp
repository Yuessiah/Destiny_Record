#include<bits/stdc++.h>
using namespace std;

int const maxn = 1e5 + 10;

int l, r;
bool vis[maxn];

int main()
{
  scanf("%d%d", &l, &r);

  for(int i = l; i <= r; i++) {
    bool ok = true;
    memset(vis, false, sizeof vis);
    int n = i;

    while(n) {
      if(vis[n%10]) { ok = false; break; }

      vis[n%10] = true;
      n /= 10;
    }

    if(ok) {
      printf("%d\n", i);
      return 0;
    }
  }

  puts("-1");

  return 0;
}
