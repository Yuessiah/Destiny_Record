#include<bits/stdc++.h>
using namespace std;
typedef long long Int;

Int n;

int main()
{
  scanf("%lld", &n);

  vector<Int> fac;
  for(Int i = 2; i*i <= n; i++) {
    if(n%i) continue;
    fac.push_back(i);
    while(n%i == 0) n /= i;
  }
  if(n != 1) fac.push_back(n);

  printf("%lld\n", (fac.size() >= 2 || fac.empty())? 1 : fac[0]);

  return 0;
}
