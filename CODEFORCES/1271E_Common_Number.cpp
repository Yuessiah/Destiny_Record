#include <bits/stdc++.h>
using namespace std;
typedef long long Int;

Int n, k;

Int chk(Int y) {
  Int x = y + !(y&1);
  Int ans = 1 + (x-y);

  while(1) {
    x <<= 1, x++;
    y <<= 1;

    if(x <= n) ans += x-y+1;
    else {
      if(y <= n) ans += n-y+1;
      break;
    }
  }

  return ans;
}

int main()
{
  scanf("%lld%lld", &n, &k);

  Int ans = 0;
  for(int p = 0; p <= 1; p++) {
    Int l = 1, r = n/2 + (n&p) + 1;
    while(l != r) {
      Int m = l + (r-l)/2;
      if(chk(2*m-p) >= k) l = m+1;
      else r = m;
    }

    ans = max(ans, 2*(l-1)-p);
  }

  printf("%lld\n", ans);

  return 0;
}
