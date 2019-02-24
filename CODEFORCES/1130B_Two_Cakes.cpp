#include<bits/stdc++.h>
using namespace std;

typedef long long Int;

int const maxn = 2e5 + 10;

Int n, a[maxn], idx[maxn];

int main()
{
  scanf("%lld", &n);

  for(int i = 0; i < 2*n; i++) {
    scanf("%lld", &a[i]);
    idx[i] = i;
  }

  sort(idx, idx+2*n, [&](Int x, Int y){ return a[x] < a[y]; });

  Int Sa = 0, Di = 0, ans = 0; // Sasha, Dima
  for(int k = 0; k < 2*n; k+=2) {
    Int s1 = abs(idx[k]-Sa) + abs(idx[k+1]-Di);
    Int s2 = abs(idx[k]-Di) + abs(idx[k+1]-Sa);

    if(s1 > s2) {
      ans += s2;
      Di = idx[k];
      Sa = idx[k+1];
    } else {
      ans += s1;
      Sa = idx[k];
      Di = idx[k+1];
    }
  }

  printf("%lld\n", ans);

  return 0;
}
