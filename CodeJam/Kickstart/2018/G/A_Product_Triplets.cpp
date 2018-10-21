#include<bits/stdc++.h>
using namespace std;

int const maxn = 7100;
typedef long long int Int;

int N;
Int a[maxn];

int main()
{
  int T, kase=0;
  scanf("%d", &T);

  while(T--) {
    scanf("%d", &N);
    for(int i = 0; i < N; i++) scanf("%lld", &a[i]);

    sort(a, a+N);

    Int cnt = 0;
    for(int i = 0; i < N-1; i++)
      for(int j = i+1; j < N; j++) {
        Int target = a[i]*a[j];
        if(target || !a[j]) cnt += upper_bound(a+j+1, a+N, target) - lower_bound(a+j+1, a+N, target);
        else cnt += upper_bound(a+i+1, a+j, 0) - lower_bound(a+i+1, a+j, 0);
      }

    printf("Case #%d: %lld\n", ++kase, cnt);
  }

  return 0;
}
