#include<bits/stdc++.h>
using namespace std;
typedef long long Int;

int const MOD = 998244353;
int const maxn = 2e5 + 10;

Int n, a[maxn], b[maxn];

int main()
{
  scanf("%lld", &n);
  for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
  for(int i = 1; i <= n; i++) scanf("%lld", &b[i]);

  for(int i = 1; i <= n; i++) a[i] *= i * (n-(i-1));

  sort(a+1, a+n+1);
  sort(b+1, b+n+1);
  reverse(b+1, b+n+1);

  Int sum = 0;
  for(int i = 1; i <= n; i++) sum = (sum + a[i]%MOD * b[i]) % MOD;

  printf("%lld\n", sum);

  return 0;
}
