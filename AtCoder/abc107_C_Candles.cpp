#include<algorithm>
#include<cstdio>
using std::min;
int const maxn = 1e5 + 10;

long N, K, x[maxn];

long labs(long p) {
  if(p < 0) return (-1)*p;
  return p;
}

int main()
{
  scanf("%ld%ld", &N, &K);

  long ans = 1e13 + 10;

  for(int i = 1; i <= N; i++) scanf("%ld", &x[i]);
  for(int i = 1; i <= N; i++) {
    if(i-0 >= K) ans = min(ans, labs(x[i])+labs(x[i]-x[i-(K-1)]));
    if((N-i+1) >= K) ans = min(ans, labs(x[i])+labs(x[i]-x[i+(K-1)]));
  }

  printf("%ld", ans);

  return 0;
}
