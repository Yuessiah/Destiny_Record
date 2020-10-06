#include<bits/stdc++.h>
using namespace std;

int const maxn = 8100;

int t, n, a[maxn], S[maxn];

int main()
{
  scanf("%d", &t);
  while(t--) {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);

    memset(S, false, sizeof S);
    for(int l = 0; l < n; l++) {
      int sum = a[l];
      for(int r = l+1; r < n; r++) {
        sum += a[r];
        if(sum > n) break;
        S[sum] = true;
      }
    }

    int cnt = 0;
    for(int i = 0; i < n; i++) if(S[a[i]]) cnt++;

    printf("%d\n", cnt);
  }

  return 0;
}
