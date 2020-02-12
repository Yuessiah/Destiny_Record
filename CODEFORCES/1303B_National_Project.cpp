#include<bits/stdc++.h>
using namespace std;

int t;
long long n, g, b;

int main()
{
  scanf("%d", &t);

  while(t--) {
    scanf("%lld%lld%lld", &n, &g, &b);

    if(g >= b) printf("%lld\n", n);
    else {
      long long need = n/2 + n%2 - 1;
      long long a = need/g*(g+b) + need%g + 1;
      long long rem_bad = need%g + 1 - n%2;
      a += max(0ll, rem_bad - need/g*(b-g));
      printf("%lld\n", a);
    }
  }

  return 0;
}

