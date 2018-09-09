#include<bits/stdc++.h>
using namespace std;

long long int n, k;

int main()
{
  scanf("%lld%lld", &n, &k);
  printf("%lld\n", k/n + bool(k%n));

  return 0;
}
