#include<bits/stdc++.h>
using namespace std;
typedef long long Int;

vector<int> const p1 {2,3,5,7,11,13,17,19,23,29,31};
vector<int> const p2 {37,41,43,47,53,59,61,67}; // #p1 + #p2 = 19
int const MOD = 1000000007;

int n, a, dp[1<<11];

int main()
{
  cin >> n;

  dp[0] = 1;
  int t[8] {};
  for(int i = 0; i < n; i++) {
    cin >> a;

    bool in_p2 = false;
    for(int j = 0; j < 8; j++)
      if(a == p2[j]) t[j]++, in_p2 = true;
    if(in_p2) continue;

    Int b = 0;
    for(int j = 0; j < 11; j++) {
      int cnt = 0;
      while(a % p1[j] == 0) a /= p1[j], cnt++;
      b |= (cnt&1LL)<<j;
    }

    int tdp[1<<11] {};
    for(int j = 0; j < 1<<11; j++) tdp[j] = (dp[j] + dp[j^b]) % MOD; // (j^b) ^ b = j
    for(int j = 0; j < 1<<11; j++) dp[j] = tdp[j];
  }

  int ans = dp[0];
  for(int i = 0; i < 8; i++)
    for(int j = 0; j < t[i]-1; j++) (ans *= 2) %= MOD; // sum of all C(t[i], even)

  cout << (ans-1+MOD) % MOD << endl;

  return 0;
}
