#include<bits/stdc++.h>
using namespace std;

int const maxn = 2e5 + 10;

long long n, m, k, a[maxn];

int main()
{
  scanf("%lld%lld%lld", &n, &m, &k);
  for(int i = 0; i < n; i++) scanf("%lld", &a[i]);

  sort(a, a+n);
  reverse(a, a+n);

  printf("%lld\n", (a[0]*k + a[1])*(m/(k+1)) + a[0]*(m%(k+1)));

  return 0;
}
