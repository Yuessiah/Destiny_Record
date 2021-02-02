#include<bits/stdc++.h>
using namespace std;

int constexpr maxn = 2e5 + 10;

int t, n, a;

int main()
{
  cin >> t;
  while(t--) {
    cin >> n;

    int f[maxn] {}, dp[maxn] {};
    for(int i = 0; i < n; i++) cin >> a, f[a]++;

    for(a = maxn-1; a; a--) {
      dp[a] = f[a];
      for(int b = 2*a; b < maxn; b+=a)
        dp[a] = max(dp[a], dp[b] + f[a]);
    }

    cout << n - dp[1] << endl;
  }

  return 0;
}
