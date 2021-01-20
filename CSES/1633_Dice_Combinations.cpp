#include<bits/stdc++.h>
using namespace std;

int const MOD = 1000000007;

int n;

int main()
{
  cin >> n;

  int dp[7] = {1};
  for(int i = 1; i <= n; i++) {
    dp[i%7] = 0;
    for(int j = 1; j <= 6; j++)
      dp[i%7] = (dp[i%7]+dp[(i+j)%7]) % MOD;
  }

  cout << dp[n%7] << endl;

  return 0;
}
