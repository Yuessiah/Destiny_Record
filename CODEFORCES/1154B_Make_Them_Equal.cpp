#include<bits/stdc++.h>
using namespace std;

int const maxn = 110;

int n, a[maxn];

int main()
{
  scanf("%d", &n);

  for(int i = 0; i < n; i++) scanf("%d", &a[i]);

  sort(a, a+n);
  n = unique(a, a+n) - a;

  int D = n>1? a[1]-a[0] : 0;

  if(n > 3) D = -1;
  if(n == 3 && D != a[2]-a[1]) D = -1;
  if(n == 2 && a[1]%2 == a[0]%2) D /= 2;

  printf("%d\n", D);

  return 0;
}
