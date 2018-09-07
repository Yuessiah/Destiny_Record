#include<bits/stdc++.h>
using namespace std;

int const maxn = 5e5 + 10;
int const INF = 1e9 + 10;

int n, a[maxn];

int main()
{
  scanf("%d", &n);

  long long int sum = 0;
  int mini = INF;
  bool pos = false, neg = false;

  for(int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    sum += abs(a[i]);
    mini = min(abs(a[i]), mini);
    if(a[i] < 0) neg = true;
    else pos = true;
  }

  if(n == 1) printf("%d\n", a[0]);
  else if(pos && neg) printf("%lld\n", sum);
  else printf("%lld\n", sum - 2*mini);

  return 0;
}
