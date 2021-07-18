#include<bits/stdc++.h>
using namespace std;

int n, m, k;

int main()
{
  cin >> n >> m >> k;

  vector<int> a(n);
  for(int& x: a) cin >> x;
  sort(a.begin(), a.end());

  multiset<int> S;
  for(int i = 0, b; i < m; i++) cin >> b, S.insert(b);

  int ans = 0;
  for(int x: a) {
    auto it = S.lower_bound(x-k);
    if(it == S.end() || *it > x+k) continue;
    S.erase(it), ans++;
  }

  cout << ans << endl;

  return 0 ;
}
