#include<bits/stdc++.h>
using namespace std;

int const maxn = 2e5 + 10;

int n, k;

int main()
{
  scanf("%d%d", &n, &k);

  vector<pair<int, int>> rng[maxn]; // range
  for(int i = 1; i <= n; i++) {
    int l, r;
    scanf("%d%d", &l, &r);
    rng[l].push_back({r, i});
  }

  vector<int> ans;
  set<pair<int, int>> cross;
  for(int i = 1; i < maxn; i++) {
    for(auto it: rng[i]) cross.insert(it);
    while(cross.size() && cross.begin()->first < i) cross.erase(cross.begin());
    while(cross.size() > k) {
      auto it = cross.end(); it--;
      ans.push_back(it->second);
      cross.erase(it);
    }
  }

  printf("%d\n", ans.size());
  for(int p: ans) printf("%d ", p);

  return 0;
}
