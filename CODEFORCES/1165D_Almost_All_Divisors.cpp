#include<bits/stdc++.h>
using namespace std;
typedef long long Int;

int const maxn = 310;

int t, n;
Int d[maxn];

int main()
{
  scanf("%d", &t);

  while(t--) {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%lld", &d[i]);


    bool ok = true;
    sort(d, d+n);
    Int x = d[0] * d[n-1];

    // factors
    vector<Int> fac;
    for(Int i = 2; i*i <= x; i++) if(x % i == 0) {
      fac.push_back(i);
      if(i != x/i) fac.push_back(x/i);
    }
    if(fac.size() != n) ok = false;

    // pair product
    for(int i = 1; i <= n/2 && ok; i++)
      if(d[i] * d[n-1-i] != x) ok = false;

    printf("%lld\n", ok? x : -1);
  }

  return 0;
}
