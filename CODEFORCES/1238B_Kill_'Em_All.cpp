#include<bits/stdc++.h>
using namespace std;

int q, n, x, r;

int main()
{
  scanf("%d", &q);

  while(q--) {
    scanf("%d%d", &n, &r);

    set<int> C; // corridor
    for(int i = 0; i < n; i++) {
      scanf("%d", &x);
      C.insert(x);
    }

    int t = 0; // times
    for(auto it = C.rbegin(); it != C.rend(); it++) {
      if(*it - (long long)t*r <= 0) break;
      else t++;
    }

    printf("%d\n", t);
  }

  return 0;
}
