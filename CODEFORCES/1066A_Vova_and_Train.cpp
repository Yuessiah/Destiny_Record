#include<bits/stdc++.h>
using namespace std;

int L, v, l, r;

int main()
{
  int t;
  scanf("%d", &t);

  while(t--) {
    scanf("%d%d%d%d", &L, &v, &l, &r);
    printf("%d\n", L/v - (r/v - (l-1)/v));
  }

  return 0;
}
