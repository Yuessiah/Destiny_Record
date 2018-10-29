#include<bits/stdc++.h>
using namespace std;

int const maxn = 1e5 + 10;

typedef long long int Int;

Int N, M, K, L, A[maxn];

int main()
{
  int T;
  scanf("%d", &T);

  while(T--) {
    scanf("%lld%lld%lld%lld", &N, &M, &K, &L);
    for(int i = 0; i < N; i++) scanf("%lld", &A[i]);

    sort(A, A+N);

    Int wait = M*L, i;
    for(i = 0; i < N; i++) {
      if(A[i] < K) wait = min(wait, (M+i - A[i]/L)*L - A[i]%L);
      else break;
    }
    wait = min(wait, (M+i - K/L)*L - K%L);

    if(wait+L > 0) printf("%lld\n", wait+L);
    else puts("0");
  }

  return 0;
}
