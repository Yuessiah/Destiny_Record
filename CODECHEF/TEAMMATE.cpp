#include<bits/stdc++.h>
using namespace std;

typedef long long int Int;

int const maxs = 1e6 + 10;
Int const MOD = 1000000007;

int N, S, cnt[maxs];
Int same[maxs];

int main()
{
  /*
   * (C(N, 2) * C(N-2, 2) * .. * C(2, 2)) / (N/2)!
   */
  same[0] = 1;
  for(Int i = 1; i < maxs-1; i+=2)
    same[i+0] = same[i+1] = (same[i-1] * i) % MOD;

  int T;
  scanf("%d", &T);

  while(T--) {
    memset(cnt, 0, sizeof(cnt));

    scanf("%d", &N);
    for(int i = 0 ; i < N; i++) {
      scanf("%d", &S);
      cnt[S]++;
    }

    Int sum = 0, pro = 1;
    for(int i = maxs-1; i >= 1; i--) if(cnt[i]) {
      pro = ( ((sum&1)? cnt[i] : 1) * ((pro * same[cnt[i] - (sum&1)]) % MOD) ) % MOD;
      sum += cnt[i];
    }

    printf("%lld\n", pro);
  }

  return 0;
}
