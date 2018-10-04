#include<bits/stdc++.h>
using namespace std;

long long int a, b, x, y;

int main()
{
  scanf("%lld%lld%lld%lld", &a, &b, &x, &y);

  long long int p = x/__gcd(x, y), q = y/__gcd(x, y);
  printf("%lld\n", min(a/p, b/q));

  return 0;
}
