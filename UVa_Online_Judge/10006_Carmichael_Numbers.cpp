#include<bits/stdc++.h>
using namespace std;

typedef long long Int;

int n;

Int exp(Int a, int m) {
  Int x = 1;

  while(m) {
    if(m&1) x = x*a % n;
    a = a*a % n;
    m >>= 1;
  }

  return x;
}

bool is_prime(int n) {
  for(int i = 2; i*i <= n; i++)
    if(!(n%i)) return false;
  return true;
}

int main()
{
  while(scanf("%d", &n) && n) {
    bool car = true;

    if(is_prime(n)) car = false;

    for(Int a = 2; a <= n-1 && car; a++)
      if(exp(a, n) != a) car = false;

    if(car) printf("The number %d is a Carmichael number.\n", n);
    else printf("%d is normal.\n", n);
  }

  return 0;
}
