#include<bits/stdc++.h>
using namespace std;

int const maxn = 2e5 + 10;

int n, a[maxn];

int main()
{
  scanf("%d", &n);
  for(int i = 0; i < n; i++) scanf("%d", &a[i]);

  sort(a, a+n);

  int cnt = 0;
  for(int i = 0; i < n; i++) if(a[i] >= cnt+1) cnt++;

  printf("%d\n", cnt);

  return 0;
}
