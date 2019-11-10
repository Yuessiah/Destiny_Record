#include<bits/stdc++.h>
using namespace std;

int const maxn = 1e3 + 10;

int k, n, a[maxn];

int main()
{
  scanf("%d", &k);

  while(k--) {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);

    sort(a, a+n);
    reverse(a, a+n);

    int i;
    for(i = 0; i < n && a[i] >= i+1; i++);

    printf("%d\n", i);
  }

  return 0;
}
