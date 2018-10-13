#include<bits/stdc++.h>
using namespace std;

int const maxn = 2e5 + 10;

int n, k, h[maxn];

int main()
{
  scanf("%d%d", &n, &k);
  for(int i = 0; i < n; i++) scanf("%d", &h[i]);


  int sum = 0, ans = 0;

  sort(h, h+n);
  for(int i = maxn; i >= 0; i--) {
    int s = n - (lower_bound(h, h+n, i) - h);
    if(s == n) {
      if(sum) ans++;
      break;
    }
    if(sum + s > k) {
      ans++;
      sum = 0;
    }
    sum += s;
  }


  printf("%d\n", ans);

  return 0;
}
