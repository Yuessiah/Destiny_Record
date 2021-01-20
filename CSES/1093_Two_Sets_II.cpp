#include<bits/stdc++.h>
using namespace std;

int const MOD = 1000000007;
int const one_over_two_MOD = 500000004;
int const maxn = 510;

long long n, dp[maxn*maxn];

int main()
{
  cin >> n;
  int mx_sum = n*(n+1)/2;

  memset(dp, 0, sizeof dp);
  dp[mx_sum] = 1;
  for(int k = 1; k <= n; k++)
    for(int s = 2*k; s <= mx_sum; s++)
      (dp[s-2*k] += dp[s]) %= MOD;

  cout << (dp[0] * one_over_two_MOD) % MOD << endl;

  return 0;
}
