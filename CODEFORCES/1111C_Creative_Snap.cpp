#include<bits/stdc++.h>
using namespace std;

typedef long long Int;

int const maxk = 1e5 + 100;

Int n, k, A, B, a[maxk];

Int dfs(int l, int r) { // [l, r)
  int n_a = upper_bound(a, a+k, r-1)-lower_bound(a, a+k, l);
  Int power = B * n_a * (r-l);

  if(!n_a) return A;
  if(r-l == 1) return power;

  int m = (l+r)/2;
  return min(power, dfs(l, m) + dfs(m, r));
}

int main()
{
  scanf("%lld%lld%lld%lld", &n, &k, &A, &B);
  for(int i = 0; i < k; i++) scanf("%lld", &a[i]);
  sort(a, a+k);

  printf("%lld\n", dfs(1, (1<<n)+1));

  return 0;
}
