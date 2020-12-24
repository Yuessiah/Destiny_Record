#include<bits/stdc++.h>
using namespace std;

int t, n, m;

int main()
{
  cin >> t;
  while(t--) {
    cin >> n >> m;

    int ans = 0, r, c;
    vector<int> e(n+1, 0);
    for(int i = 0; i < m; i++) {
      cin >> c >> r;
      if(r == c) continue;
      e[c] = r, ans++;
    }

    vector<bool> vis(n+1, false);
    for(int d = 1; d <= n; d++) {
      if(!e[d] || vis[d]) continue;

      int c = d;
      vis[c] = true;
      while(e[c] && !vis[e[c]]) vis[c=e[c]] = true;
      if(e[c] == d) ans++;
    }

    cout << ans << endl;
  }

  return 0;
}
