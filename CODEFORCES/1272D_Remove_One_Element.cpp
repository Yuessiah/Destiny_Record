#include<bits/stdc++.h>
using namespace std;

int const maxn = 2e5 + 10;

int n, a[maxn], dp[maxn][2];

int main()
{
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) scanf("%d", &a[i]);

  int ans = 0;

  for(int i = 1; i <= n; i++) {
    if(a[i] > a[i-1]) dp[i][0] = dp[i-1][0] + 1;
    else dp[i][0] = 1;

    ans = max(ans, dp[i][0]);
  }

  dp[n][1] = 1;
  for(int i = n-1; i > 0; i--) {
    if(a[i] < a[i+1]) dp[i][1] = dp[i+1][1] + 1;
    else dp[i][1] = 1;
  }

  for(int i = 2; i < n; i++)
    if(a[i-1] < a[i+1]) ans = max(ans, dp[i-1][0] + dp[i+1][1]);

  printf("%d\n", ans);

  return 0;
}
