#include<bits/stdc++.h>
using namespace std;

typedef long long Int;
Int const MOD = 1000000007;

Int x, n;
vector<Int> prime;

Int _pow(Int a, Int n) {
  Int x = 1LL;
  while(n) {
    if(n&1LL) x = (x * a) % MOD;
    a = (a * a) % MOD;
    n >>= 1;
  }

  return x;
}

int main()
{
  scanf("%lld%lld", &x, &n);

  for(Int i = 2; i*i <= x; i++)
    if(x%i == 0) {
      prime.push_back(i);
      while(x%i == 0) x /= i;
    }
  if(x > 1) prime.push_back(x);

  Int ans = 1;
  for(Int a: prime) {
    Int cnt = 0, A = a;
    while(1) {
      cnt += n/A;
      if(A > n/a) break;
      A *= a;
    }
    ans = (ans * _pow(a, cnt)) % MOD;
  }

  printf("%lld\n", ans);

  return 0;
}
