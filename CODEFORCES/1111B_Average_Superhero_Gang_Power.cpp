#include<bits/stdc++.h>
using namespace std;

int const maxn = 1e5 + 10;

long long n, k, m, a[maxn];

int main()
{
  scanf("%lld%lld%lld", &n, &k, &m);
  for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);

  sort(a+1, a+n+1);
  reverse(a+1, a+n+1);

  double sum = 0, maxi = 0;
  for(int i = 1; i <= n; i++) {
    sum += a[i];
    if(m-n+i >= 0) maxi = max(maxi, (sum+min(k*i, m-n+i))/i);
  }

  printf("%lf\n", maxi);

  return 0;
}
