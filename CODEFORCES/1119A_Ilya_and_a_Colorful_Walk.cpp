#include<bits/stdc++.h>
using namespace std;

int const maxn = 3e5 + 10;

int n, c[maxn];

int main() {
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) scanf("%d", &c[i]);

  int p1, p2;
  for(int i = 1; i <= n; i++)
    if(c[i] != c[1]) p1 = i;
  for(int i = n; i >= 1; i--)
    if(c[i] != c[n]) p2 = i;

  printf("%d\n", max(p1-1, n-p2));

  return 0;
}
