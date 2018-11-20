#include<bits/stdc++.h>
using namespace std;

int const maxn = 2e5 + 10;

int n, k, s, cnt[maxn];

int main()
{
  scanf("%d%d", &n, &k);

  for(int i = 0; i < n; i++) {
    scanf("%d", &s);
    cnt[s]++;
  }

  // upper bound
  int l = 1, r = n+1;
  while(l != r) {
    int m = (l + r) / 2, c = 0;
    for(int i = 0; i < maxn; i++) c += cnt[i]/m;
    if(c >= k) l = m + 1;
    else r = m;
  }

  for(int i = 0; i < maxn; i++)
    for(int j = 0; j < cnt[i]/(l-1) && k; j++, k--) printf("%d ", i);

  return 0;
}
