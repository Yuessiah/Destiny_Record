#include<bits/stdc++.h>
using namespace std;

int const maxn = 3e5 + 10;

int n, m;
long long x[maxn], p[maxn];

int main()
{
  scanf("%d%d", &n, &m);
  for(int i = 0; i < n; i++) scanf("%lld", &x[i]);
  for(int i = 0; i < m; i++) scanf("%lld", &p[i]);

  long long g = x[1]-x[0];
  for(int i = 2; i < n; i++) g = __gcd(g, x[i]-x[i-1]);

  for(int i = 0; i < m; i++) {
    if(g % p[i] == 0) {
      puts("YES");
      printf("%lld %d\n", x[0], i+1);
      return 0;
    }
  }

  puts("NO");

  return 0;
}
