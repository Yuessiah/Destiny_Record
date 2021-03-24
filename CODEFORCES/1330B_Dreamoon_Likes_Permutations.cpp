#include<bits/stdc++.h>
using namespace std;

int constexpr maxn = 2e5 + 10;

int t, n, a[maxn];

int main()
{
  cin >> t;
  while(t--) {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];

    set<int> S, l1;
    for(int i = 0; i < n-1; i++) {
      S.insert(a[i]);
      auto it = S.rbegin();
      if(*it == S.size() && *it+(n-i-1) == n) l1.insert(*it);
    }

    vector<pair<int, int>> ans;
    S.clear();
    for(int i = n-1; i >= 1; i--) {
      S.insert(a[i]);
      auto it = S.rbegin();
      if(*it == S.size() && l1.count(i) && i+*it == n) ans.push_back({i, *it});
    }

    cout << ans.size() << endl;
    for(auto [f, s]: ans) cout << f << ' ' << s << endl;
  }

  return 0;
}
