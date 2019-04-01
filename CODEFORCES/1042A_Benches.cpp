#include<bits/stdc++.h>
using namespace std;

int const maxn = 110;

int n, m, a[maxn];

int main()
{
  scanf("%d%d", &n, &m);
  for(int i = 0; i < n; i++) scanf("%d", &a[i]);

  int p = *max_element(a, a+n), sum = 0;
  for(int i = 0; i < n; i++) sum += p-a[i];

  if(m > sum) printf("%d ", p + (m-sum)/n + !!((m-sum)%n));
  else printf("%d ", p);

  printf("%d\n", p+m);


  return 0;
}
