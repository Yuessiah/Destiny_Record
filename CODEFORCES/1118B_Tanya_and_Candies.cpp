#include<bits/stdc++.h>
using namespace std;

int const maxn = 2e5 + 10;

int n, a[maxn];

int main()
{
  scanf("%d", &n);

  int sum[2] = {};
  for(int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    sum[i&1] += a[i];
  }

  int cnt = 0;
  for(int i = 0; i < n; i++) {
    sum[i&1] -= a[i];
    sum[i&1] += i? a[i-1] : 0;
    if(sum[0] == sum[1]) cnt++;
  }

  printf("%d\n", cnt);

  return 0;
}
