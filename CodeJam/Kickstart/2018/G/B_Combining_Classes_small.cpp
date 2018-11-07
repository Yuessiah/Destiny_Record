#include<bits/stdc++.h>
using namespace std;

typedef long long int Int;

int const maxn = 4e5 + 10, MOD = 1000000000;

int N, Q;
Int X[maxn], Y[maxn], Z[maxn], L[maxn], R[maxn];
Int A1, A2, A3, B1, B2, B3, C1, C2, C3, M1, M2, M3;

Int larger(Int v) {
  Int cnt = 0;
  for(int i = 1; i <= N; i++) {
    if(v > R[i]) continue;
    cnt += R[i] - max(v, L[i]) + 1;
  }

  return cnt;
}

int bs(int target) {
  int l = 0, r = MOD + 1, res;

  while(l != r) {
    int m = l + (r-l)/2;
    if(larger(m) >= target) {
      l = m + 1;
      res = m;
    } else r = m;
  }

  return res;
}

int main()
{
  int T, kase = 0;
  scanf("%d", &T);

  while(T--) {
    scanf("%d%d", &N, &Q);
    scanf("%lld%lld%lld%lld%lld%lld", &X[1], &X[2], &A1, &B1, &C1, &M1);
    scanf("%lld%lld%lld%lld%lld%lld", &Y[1], &Y[2], &A2, &B2, &C2, &M2);
    scanf("%lld%lld%lld%lld%lld%lld", &Z[1], &Z[2], &A3, &B3, &C3, &M3);

    //init
    for(int i = 3; i <= N; i++) {
      X[i] = (A1*X[i-1] + B1*X[i-2] + C1) % M1;
      Y[i] = (A2*Y[i-1] + B2*Y[i-2] + C2) % M2;
    }
    for(int i = 3; i <= Q; i++)
      Z[i] = (A3*Z[i-1] + B3*Z[i-2] + C3) % M3;

    for(int i = 1; i <= N; i++) {
      L[i] = min(X[i], Y[i]) + 1;
      R[i] = max(X[i], Y[i]) + 1;
    }
    for(int i = 1; i <= Q; i++) Z[i]++;

    //solution
    Int ans = 0;
    for(int i = 1; i <= Q; i++)
      ans += i * bs(Z[i]);

    printf("Case #%d: %lld\n", ++kase, ans);
  }

  return 0;
}
