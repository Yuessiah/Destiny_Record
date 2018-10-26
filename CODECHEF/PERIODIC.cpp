#include<bits/stdc++.h>
using namespace std;

int const maxn = 1e5 + 10;

int N, a[maxn];

int main()
{
  int T;
  scanf("%d", &T);

  while(T--) {
    int prev = -1, peri = 0, maxi = -2;

    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
      scanf("%d", &a[i]);
      maxi = max(maxi, a[i]);

      if(a[i] != -1) {
        if(~prev) peri = __gcd(peri, (a[prev]-prev) - (a[i]-i));
        prev = i;
      }
    }

    if(!peri) puts("inf");
    else if(peri < maxi) puts("impossible");
    else printf("%d\n", peri);
  }

  return 0;
}
