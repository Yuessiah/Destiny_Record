#include<bits/stdc++.h>
using namespace std;

int const maxn = 1e5 + 10;

int n, m;

int main()
{
  scanf("%d%d", &n, &m);

  long long bal[maxn] = {}; // balance
  while(m--) {
    int u, v, d;
    scanf("%d%d%d", &u, &v, &d);
    bal[u] += d;
    bal[v] -= d;
  }

  vector<int> pos, neg;
  for(int i = 1; i <= n; i++) {
    if(bal[i] < 0) neg.push_back(i);
    if(bal[i] > 0) pos.push_back(i);
  }

  vector<tuple<int, int, long long>> ans;
  while(pos.size() || neg.size()) {
    int &u = pos.back(), &v = neg.back();

    long long d = min(bal[u], -bal[v]);
    ans.push_back({u, v, d});
    bal[u] -= d;
    bal[v] += d;

    if(bal[u] == 0) pos.pop_back();
    if(bal[v] == 0) neg.pop_back();
  }

  printf("%lu\n", ans.size());
  for(auto [u, v, d]: ans) printf("%d %d %lld\n", u, v, d);

  return 0;
}
