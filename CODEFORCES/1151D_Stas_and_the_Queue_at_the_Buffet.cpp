#include<bits/stdc++.h>
using namespace std;

typedef long long Int;

int const maxn = 1e5 + 10;

int n;
Int a, b, c[maxn];

int main()
{
  scanf("%d", &n);

  /* a*(j-1) + b*(n-j) = (a-b)*j + b*n - a */
  Int sum = 0;
  for(int i = 0; i < n; i++) {
    scanf("%lld%lld", &a, &b);
    sum += b*n - a;
    c[i] = a - b;
  }

  sort(c, c+n);
  for(int i = 0; i < n; i++) sum += c[i] * (n-i);

  printf("%lld\n", sum);

  return 0;
}
