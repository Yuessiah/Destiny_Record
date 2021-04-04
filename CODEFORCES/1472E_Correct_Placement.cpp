#include<bits/stdc++.h>
using namespace std;
typedef tuple<int, int, int> t3i;

int t, n;

int main()
{
  cin >> t;
  while(t--) {
    cin >> n;

    vector<t3i> f(n);
    for(int i = 0; i < n; i++) {
      auto& [h, w, j] = f[i];
      cin >> h >> w, j = i;
      if(h > w) swap(h, w);
    }
    sort(f.begin(), f.end());

    int p = 0;
    vector<int> ans(n, -1);
    priority_queue<t3i, vector<t3i>, greater<t3i>> pq;
    for(int i = 1; i < n; i++) {
      auto [h1, w1, j1] = f[i];
      auto [h2, w2, j2] = f[i-1];

      if(h1 > h2) {
        for(int k = p; k < i; k++) {
          auto [h, w, j] = f[k];
          pq.push({w, h, j});
        }
        p = i;
      }

      if(pq.empty()) continue;
      auto [w, h, j] = pq.top();
      if(w < w1) ans[j1] = j + 1;
    }

    for(int i: ans) cout << i << ' ';
    cout << endl;
  }

  return 0;
}
