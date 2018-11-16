#include<bits/stdc++.h>
using namespace std;

long long int a, b, k;

int main()
{
  int t;
  scanf("%d", &t);

  while(t--) {
    scanf("%lld%lld%lld", &a, &b, &k);
    printf("%lld\n", a*(k/2 + (k&1)) - b*(k/2));
  }

  return 0;
}
