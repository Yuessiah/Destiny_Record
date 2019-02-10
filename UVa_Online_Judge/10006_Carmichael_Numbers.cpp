#include<bits/stdc++.h>
using namespace std;

typedef long long Int;

int const maxn = 65535;

bool car[maxn];

Int exp(Int a, int m, int n) {
  Int x = 1;

  while(m) {
    if(m&1) x = x*a % n;
    a = a*a % n;
    m >>= 1;
  }

  return x;
}

int main()
{
  memset(car, false, sizeof car);

  for(Int i = 2; i < maxn; i++) {
    if(car[i]) continue;
    for(Int j = i*i; j < maxn; j+=i) car[j] = true;
  }

  for(int n = 2; n < maxn; n++)
    for(Int a = 2; a <= n-1 && car[n]; a++)
      if(exp(a, n, n) != a) car[n] = false;

  int n;
  while(scanf("%d", &n) && n) {
    if(car[n]) printf("The number %d is a Carmichael number.\n", n);
    else printf("%d is normal.\n", n);
  }

  return 0;
}
