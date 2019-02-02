#include<algorithm>
#include<cstdio>
using std::max;

typedef long long Int;

int const maxn = 1e6 + 100;

Int N, K, a[maxn];

int main()
{
  scanf("%lld%lld", &N, &K);
  for(int i = 0; i < N; i++) scanf("%lld", &a[i]);

  Int pre = 0, maxi = a[0];
  for(int u = 0; u < K; u++) { // u := used
    pre += a[u];
    maxi = max(maxi, pre + ((K-u)/2) * (a[u]+a[u+1]) + ((K-u)&1) * a[u+1]);
  }

  printf("%lld\n", maxi);

  return 0;
}
