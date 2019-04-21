#include<bits/stdc++.h>
using namespace std;

typedef long long Int;
int const MOD = 1000000007;

Int l, r;

Int sum(Int n) {
  bool p = 1; // parity
  Int cnt[2] = {0, 0};

  for(Int x = 1, s = 1;; s+=x*=2) { // s := step
    if(s >= n) {
      cnt[p] = (cnt[p] + n - (s-x)) % MOD;
      break;
    }

    cnt[p] = (cnt[p] + x) % MOD;
    p ^= 1;
  }

  return (cnt[0]*(cnt[0]+1) + cnt[1]*cnt[1]) % MOD;
}

int main() {
  scanf("%lld%lld", &l, &r);
  printf("%lld\n", (sum(r) - sum(l-1) + MOD) % MOD);

  return 0;
}
