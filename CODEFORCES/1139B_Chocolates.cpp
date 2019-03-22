#include<bits/stdc++.h>
using namespace std;

int const maxn = 2e5 + 10;

int n;
long long a[maxn], b[maxn];

int main()
{
  scanf("%d", &n);
  for(int i = 0; i < n; i++) scanf("%lld", &a[i]);

  long long buy = b[n-1] = a[n-1];
  //printf("buy = %lld\n", buy);
  for(int i = n-2; i >= 0; i--) {
    b[i] = min(a[i], max(b[i+1]-1, 0LL));
    buy += b[i];
  }

  printf("%lld\n", buy);

  return 0;
}
