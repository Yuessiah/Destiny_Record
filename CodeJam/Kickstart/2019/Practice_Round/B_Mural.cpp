#include<bits/stdc++.h>
using namespace std;

int const maxn = 5e6 + 10;

int T, N, pre[maxn];
char d;

int main()
{
  int kase = 0;
  scanf("%d\n", &T);

  while(T--) {
    scanf("%d\n", &N);

    pre[0] = 0;
    for(int i = 1; i <= N; i++) {
      scanf(" %c", &d);
      pre[i] = pre[i-1] + (d-'0');
    }

    int maxi = 0;
    for(int j = 0, i = (N+1)/2; i <= N; j++, i++)
      maxi = max(maxi, pre[i]-pre[j]);

    printf("Case #%d: %d\n", ++kase, maxi);
  }

  return 0;
}
