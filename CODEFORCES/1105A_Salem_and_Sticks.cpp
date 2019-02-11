#include<bits/stdc++.h>
using namespace std;

int const maxn = 1010, maxa = 110;

int n, a[maxn];

int main()
{
  scanf("%d", &n);
  for(int i = 0; i < n; i++) scanf("%d", &a[i]);

  int t, ans = maxn*maxa;
  for(int __t = 1; __t <= maxa; __t++) {
    int sum = 0;
    for(int i = 0; i < n; i++) sum += max(0, abs(a[i]-__t) - 1);

    if(ans > sum) ans = sum, t = __t;
  }

  printf("%d %d\n", t, ans);

  return 0;
}
