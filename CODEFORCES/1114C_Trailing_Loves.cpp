#include<bits/stdc++.h>
using namespace std;

typedef long long Int;

Int const INF = 0x3f3f3f3f3f3f3f3f;

struct factor { Int p, t; };

Int n, b;
vector<factor> facs;

int main()
{
  scanf("%lld%lld", &n, &b);

  Int B = b;
  for(Int p = 2; p*p <= b; p++) {
    Int t = 0;
    while(B%p == 0) B /= p, t++;

    if(t) facs.push_back({p, t});
  }
  if(B != 1) facs.push_back({B, 1});

  Int ans = INF;
  for(auto fac: facs) {
    Int N = n, sum = 0;
    while(N/=fac.p) sum += N;

    ans = min(ans, sum/fac.t);
  }

  printf("%lld\n", ans);

  return 0;
}
