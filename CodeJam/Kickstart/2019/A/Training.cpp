#include<bits/stdc++.h>
using namespace std;

int const maxn = 1e5 + 10;

int N, P, S[maxn];

int main()
{
  int T, kase=0;
  scanf("%d", &T);

  while(T--) {
    scanf("%d%d", &N, &P);
    for(int i = 0; i < N; i++) scanf("%d", &S[i]);

    sort(S, S+N);
    reverse(S, S+N);

    int hour = 0;
    for(int r = 0; r < P; r++) hour += S[0]-S[r];

    int ans = hour;
    for(int l = 1; l < N-P+1; l++) {
      hour -= (P-1) * (S[l-1]-S[l]);
      hour += S[l] - S[l+P-1];
      ans = min(ans, hour);
    }

    printf("Case #%d: %d\n", ++kase, ans);
  }

  return 0;
}
