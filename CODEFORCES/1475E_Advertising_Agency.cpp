#include<bits/stdc++.h>
using namespace std;

int constexpr MOD = 1000000007;
int constexpr maxn = 1e3 + 10;

int t, n, k, a[maxn];

int main()
{
  cin >> t;
  while(t--) {
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n);
    reverse(a, a+n);

    int l = k-1, r = k;
    while(l < n && a[l] == a[l-1]) l--;
    while(r < n && a[r-1] == a[r]) r++;

    vector<int> f(k-l);
    iota(f.begin(), f.end(), r-k+1);
    for(int d = 1; d <= k-l; d++) {
      int y = d;
      for(int& x: f) {
        int g = __gcd(x, y);
        x /= g, y /= g;
        if(y == 1) break;
      }
    }

    long long ans = 1;
    for(int x: f) (ans *= x) %= MOD;

    cout << ans << endl;
  }

  return 0;
}
