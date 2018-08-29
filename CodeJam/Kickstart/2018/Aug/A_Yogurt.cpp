#include<bits/stdc++.h>
using namespace std;

int const maxn = 5e3 + 10;

int N, K, a[maxn];

int main()
{
  int T, kase = 0;
  scanf("%d", &T);

  while(T--) {
    scanf("%d%d", &N, &K);
    for(int i = 0; i < N; i++) scanf("%d", &a[i]);

    sort(a, a+N);

    int day = 0, eat = 0;
    for(int i = 0; i < N; i++) {
      if(!(a[i] -= day)) continue;
      if(!((++eat)%K)) day++;
    }

    printf("Case #%d: %d\n", ++kase, eat);
  }

  return 0;
}
