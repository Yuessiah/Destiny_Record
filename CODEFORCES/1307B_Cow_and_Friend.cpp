#include<bits/stdc++.h>
using namespace std;

int const maxn = 1e5 + 10;

int t, n, x, a[maxn];

int main()
{
  scanf("%d", &t);

  while(t--) {
    scanf("%d%d", &n, &x);

    int mx = 0;
    bool eq = false;
    for(int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      if(a[i] == x) eq = true;
      mx = max(mx, a[i]);
    }

    if(eq) puts("1");
    else if(mx > x) puts("2");
    else printf("%d\n", x/mx + !!(x%mx));
  }

  return 0;
}
