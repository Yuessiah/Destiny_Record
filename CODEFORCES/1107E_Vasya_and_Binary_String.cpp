#include<bits/stdc++.h>
using namespace std;

int const maxn = 105;

int n, a[maxn];
long long dp[2][maxn][maxn][maxn];
string s;

long long dfs(char bin, int cnt, int l, int r) {
  if(l == r) return a[cnt];

  long long &ret = dp[bin-'0'][cnt][l][r];
  if(ret) return ret;

  for(int i = l; i < r; i++)
    if(s[i] == bin) ret = max(ret,
        max(dfs('0', 0, l, i), dfs('1', 0, l, i)) + dfs(bin, cnt+1, i+1, r));

  return ret;
}

int main()
{
  memset(dp, 0, sizeof dp);

  cin >> n >> s;

  a[0] = 0;
  for(int i = 1; i <= n; i++) cin >> a[i];

  cout << max(dfs('0', 0, 0, n), dfs('1', 0, 0, n)) << endl;

  return 0;
}
