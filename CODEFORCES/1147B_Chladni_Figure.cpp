#include<bits/stdc++.h>
using namespace std;

int n, m;

int main()
{
  cin >> n >> m;

  set<pair<int, int>> s;
  for(int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    if(a > b) swap(a, b);
    s.insert({a-1, b-1});
  }

  vector<int> f {1};
  for(int d = 2; d*d <= n; d++) {
    if(n%d) continue;
    f.push_back(d);
    f.push_back(n/d);
  }

  bool ans = false;
  for(int k: f) {
    bool ok = true;
    for(auto [a, b]: s) {
      int _a = (a+k)%n, _b = (b+k)%n;
      if(_a > _b) swap(_a, _b);
      if(!s.count({_a, _b})) { ok = false; break; }
    }

    ans = ans | ok;
  }

  puts(ans? "Yes" : "No");

  return 0;
}
