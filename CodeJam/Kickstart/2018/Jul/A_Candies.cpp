#include<bits/stdc++.h>
using namespace std;

int const maxn = 5e5 + 10;
long const INF = 0x7fffffffffffffff;

int N, O, A, B, C, M, L;
long D, X[maxn], S[maxn], sum[maxn];

int main()
{
  int T, kase = 0;
  scanf("%d", &T);

  S[0] = sum[0] = 0;
  while(T--) {
    scanf("%d%d%ld", &N, &O, &D);
    scanf("%ld%ld%d%d%d%d%d", &X[1], &X[2], &A, &B, &C, &M, &L);

    // init
    for(int i = 3; i <= N; i++) X[i] = (A*X[i-1] + B*X[i-2] + C) % M;
    for(int i = 1; i <= N; i++) S[i] = X[i] + L;

    for(int i = 1; i <= N; i++) sum[i] = sum[i-1] + S[i];

    //solve
    multiset<long> MS;
    queue<long> Q;
    MS.insert(0); Q.push(0);

    int odd = 0, l = 1; // l := left
    long ans = -INF;

    for(int i = 1; i <= N; i++) {
      Q.push(sum[i]);
      if(S[i] & 1) odd++;

      while(odd > O) {
        MS.erase(MS.find(Q.front())); Q.pop();
        if(S[l++] & 1) odd--;
      }

      auto it = MS.lower_bound(sum[i] - D);
      if(it != MS.end()) ans = max(ans, sum[i] - *it);
      MS.insert(sum[i]);
    }

    //answer
    printf("Case #%d: ", ++kase);
    if(ans == -INF) puts("IMPOSSIBLE");
    else printf("%ld\n", ans);
  }
}
