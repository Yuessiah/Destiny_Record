#include<bits/stdc++.h>
using namespace std;

typedef long long Int;

int t;
Int n, m;

int main()
{
  scanf("%d", &t);
  while(t--) {
    scanf("%lld%lld", &n, &m);
    Int f = n*(1+n)/2;
    Int q = (n-m)/(m+1), r = (n-m)%(m+1);
    f -= q*(1+q)/2*(m+1-r) + (q+1)*(1+q+1)/2*r;

    printf("%lld\n", f);
  }

  return 0;
}
