#include<bits/stdc++.h>
using namespace std;

int const maxn = 3e5 + 10;

int n, x;
long long a[maxn];

int main()
{
  scanf("%d%d", &n, &x);

  long long best = 0, dp[maxn][3] = {};
  for(int r = 1; r <= n; r++) {
    scanf("%lld", &a[r]);

    dp[r][0] = max(dp[r-1][0] + a[r], a[r]);
    dp[r][1] = max(dp[r-1][0] + a[r]*x, max(dp[r-1][1] + a[r]*x, a[r]*x));
    dp[r][2] = max(dp[r-1][1] + a[r], max(dp[r-1][2] + a[r], a[r]));

    best = max(best, max(dp[r][0], max(dp[r][1], dp[r][2])));
  }

  printf("%lld\n", best);

  return 0;
}
