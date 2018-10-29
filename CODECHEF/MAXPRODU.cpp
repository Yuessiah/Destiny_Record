#include<bits/stdc++.h>
using namespace std;

typedef long long int Int;
Int const MOD = 1000000007;

Int N, K;

int main()
{
  int T;
  scanf("%d", &T);

  while(T--) {
    scanf("%lld %lld", &N, &K);

    Int K_seri = K*(K+1) / 2;
    if(N < K_seri) { puts("-1"); continue; }

    Int pro = 1;
    Int mean = (N-K_seri) / K, rem = (N-K_seri) % K;

    for(Int y = mean+K; y >= mean+1; y--) {
      Int x = y + ((rem-- > 0)? 1 : 0);
      pro = pro * (x*(x-1) % MOD) % MOD;
    }
    printf("%lld\n", pro);
  }

  return 0;
}
