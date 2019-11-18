#include<bits/stdc++.h>
using namespace std;
typedef long long Int;

int const maxn = 2e5 + 10;

int n, m;
Int a[maxn];

int main()
{
  scanf("%d%d", &n, &m);

  for(int i = 0; i < n; i++) scanf("%lld", &a[i]);
  sort(a, a+n);

  Int sum = 0;
  for(int i = 0; i < n; i++) {
    if(i >= m) a[i] += a[i-m];
    printf("%lld ", sum += a[i]);
  }
  putchar('\n');

  return 0;
}
