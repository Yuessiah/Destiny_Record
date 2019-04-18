#include<bits/stdc++.h>
using namespace std;

typedef long long Int;

int const maxn = 1e5 + 10;

int n;
struct student { Int a, b; } s[maxn];

bool cmp(student const &x, student const &y)
  { return (x.a-y.a) + (y.b-x.b) > 0; }

int main()
{
  scanf("%d", &n);
  for(int i = 0; i < n; i++) scanf("%lld%lld", &s[i].a, &s[i].b);

  sort(s, s+n, cmp);

  Int sum = 0;
  for(int i = 0; i < n; i++) sum += s[i].a * i + s[i].b * (n-(i+1));

  printf("%lld\n", sum);

  return 0;
}
