#include<bits/stdc++.h>
using namespace std;

long long q, n, a, b;

int main()
{
  scanf("%lld", &q);

  while(q--) {
    scanf("%lld%lld%lld", &n, &a, &b);

    long long aa = 2*a;
    printf("%lld\n", ((aa>b)? (n/2)*b : (n/2)*aa) + (n&1)*a);
  }

  return 0;
}
