#include<bits/stdc++.h>
using namespace std;

int const maxn = 1e3 + 10;
int const maxx = 1e5 + 10;

int n, x, h[maxn], s[maxn], dp[maxx];

int main()
{
  cin >> n >> x;
  for(int i = 0; i < n; i++) cin >> h[i];
  for(int i = 0; i < n; i++) cin >> s[i];

  for(int i = 0; i < n; i++)
    for(int k = x; k >= h[i]; k--)
      dp[k] = max(dp[k], dp[k-h[i]] + s[i]);

  cout << dp[x] << endl;

  return 0;
}
