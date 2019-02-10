#include<bits/stdc++.h>
using namespace std;

int const maxn = 3e5 + 10;

int n, a[maxn];

int main()
{
  scanf("%d", &n);
  for(int i = 0; i < n; i++) scanf("%d", &a[i]);
  sort(a, a+n);

  long long sum = 0;
  for(int i = 0; i < n/2; i++) sum += (a[i]+a[n-1-i])*(a[i]+a[n-1-i]);

  printf("%lld\n", sum);

  return 0;
}
