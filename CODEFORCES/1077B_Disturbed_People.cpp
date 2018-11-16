#include<bits/stdc++.h>
using namespace std;

int const maxn = 105;

int n, a[maxn];

int main()
{
  scanf("%d", &n);
  for(int i = 0; i < n; i++) scanf("%d", &a[i]);

  int cnt = 0;
  for(int i = 1; i < n-1; i++)
    if(a[i-1] && !a[i] && a[i+1]) cnt++, a[i+1] = 0;

  printf("%d\n", cnt);

  return 0;
}
