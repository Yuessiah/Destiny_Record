#include<bits/stdc++.h>
using namespace std;

int const maxn = 2e5 + 10;

int Q, n, ans[maxn];
char big[6*maxn];

int main()
{
  for(int N = 1; N < maxn; N++) ans[N] = N;

  int p = 6;
  for(int N = 1; N < maxn; N++) {
    char S[6];
    sprintf(S, "%d", N);

    for(int i = 0; i < strlen(S); i++) {
      big[++p] = S[i];

      for(int l = 0; l < 6; l++) {
        big[p+1] = '\0';
        int num = atoi(&big[p - l]);
        if(num < maxn) ans[num] = min(ans[num], N);
      }
    }
  }


  scanf("%d", &Q);

  while(Q--) {
    scanf("%d", &n);
    printf("%d\n", ans[n]);
  }

  return 0;
}
