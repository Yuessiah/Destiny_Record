#include<bits/stdc++.h>
using namespace std;

int const maxn = 1e3 + 10;
int const mod = 1000000007;

int n, m, p[maxn];

int main()
{
  cin >> n >> m;

  for(int i = 1; i <= n; i++) p[i] = 1;

  for(int r = 0; r < 2*m; r++) // r := round
    for(int b = n; b >= 1; b--) { // b := bound
      long long sum = 0;
      for(int i = 1; i <= b; i++) sum = (sum + p[i]) % mod;

      p[b] = sum;
    }

  cout << p[n] << endl;

  return 0;
}
