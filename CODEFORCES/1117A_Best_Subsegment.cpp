#include<bits/stdc++.h>
using namespace std;

int const maxn = 1e5 + 10;

int n, a[maxn];

int main()
{
  scanf("%d", &n);
  for(int i = 0; i < n; i++) scanf("%d", &a[i]);

  int maxi = *max_element(a, a+n), cnt = 0, ans = 0;
  for(int i = 0; i < n; i++) {
    if(maxi == a[i]) cnt++;
    else cnt = 0;

    ans = max(ans, cnt);
  }

  printf("%d\n", ans);

  return 0;
}
