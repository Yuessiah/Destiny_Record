#include<bits/stdc++.h>
using namespace std;
typedef long long Int;

int q;
Int n;

int main()
{
  scanf("%d", &q);

  while(q--) {
    scanf("%lld", &n);

    Int res = 0, exp3 = 1;
    while(res <= n) res += exp3, exp3 *= 3;
    while(exp3) {
      if(res - exp3 >= n) res -= exp3;
      exp3 /= 3;
    }

    printf("%lld\n", res);
  }

  return 0;
}
