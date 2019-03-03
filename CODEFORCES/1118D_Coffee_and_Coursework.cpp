#include<bits/stdc++.h>
using namespace std;

int const maxn = 2e5 + 10;

int n, m, a[maxn];

bool done(int d) {
  long long page = 0;

  for(int i = 0; i < n; i++)
    page += max(a[i] - i/d, 0);

  return page >= m;
}

int main()
{
  scanf("%d%d", &n, &m);

  for(int i = 0; i < n; i++) scanf("%d", &a[i]);
  sort(a, a+n, greater<int>());

  int l = 1, r = n+1;
  while(l != r) {
    int day = (l+r)/2;

    if(done(day)) r = day;
    else l = day+1;
  }

  printf("%d\n", (l <= n)? l : -1);

  return 0;
}
