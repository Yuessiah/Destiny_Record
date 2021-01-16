#include<bits/stdc++.h>
using namespace std;
typedef long long Int;

int constexpr maxn = 1e6 + 10;

int n;
Int a[maxn];

int main()
{
  ios::sync_with_stdio(false), cin.tie(0);

  cin >> n;
  for(int i = 0; i < n; i++) cin >> a[i];

  Int ans = 0;
  vector<int> idx(n);
  iota(idx.begin(), idx.end(), 0);
  sort(idx.begin(), idx.end(), [](int x, int y) { return a[x] > a[y]; });

  for(int t = 0; t < 2; t++) {
    set<int> S {-1, n};
    for(int i: idx) {
      auto p = S.insert(i).first;
      ans += a[i] * (i-*prev(p)) * (*next(p)-i);
    }

    transform(a, a+n, a, [](Int v) { return -v; });
    reverse(idx.begin(), idx.end());
  }

  cout << ans << endl;

  return 0;
}
