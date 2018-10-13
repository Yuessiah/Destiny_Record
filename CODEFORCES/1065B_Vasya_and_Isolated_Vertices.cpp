#include<bits/stdc++.h>
using namespace std;

typedef long long int Int;

Int n, m;

int main()
{
  scanf("%lld%lld", &n, &m);
  Int w = ceil((1 + sqrt(1+8*m))/2);
  printf("%lld %lld", max(n-2*m, (Int)0), m? max(n-w, (Int)0): n);

  return 0;
}
