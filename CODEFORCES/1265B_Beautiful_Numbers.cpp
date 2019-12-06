#include<bits/stdc++.h>
using namespace std;

int const maxn = 2e5 + 10;

int t, n;

int main()
{
  scanf("%d", &t);

  while(t--) {
    scanf("%d", &n);

    int pos[maxn], p;
    for(int i = 0; i < n; i++) {
      scanf("%d", &p);
      pos[p] = i;
    }

    int l = pos[1], r = pos[1];
    for(int m = 1; m <= n; m++) {
      if(pos[m] > r) r = pos[m];
      if(pos[m] < l) l = pos[m];
      printf("%d", r-l+1 == m);
    }
    putchar('\n');
  }

  return 0;
}
