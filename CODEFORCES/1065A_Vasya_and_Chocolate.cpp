#include<bits/stdc++.h>
using namespace std;

long long int s, a, b, c;

int main()
{
  int t;
  scanf("%d", &t);

  while(t--) {
    scanf("%lld%lld%lld%lld", &s, &a, &b, &c);
    printf("%lld\n", (s/c) + ((s/c)/a)*b);
  }

  return 0;
}
