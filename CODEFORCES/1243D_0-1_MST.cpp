#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;

int const maxn = 1e5 + 10;

int n, m, a, b;
set<int> g[maxn];

int main() {
  scanf("%d%d", &n, &m);
  while(m--) {
    scanf("%d%d", &a, &b);
    g[a].insert(b);
    g[b].insert(a);
  }


  int comp = 0;
  set<int> rest;
  for(int i = 1; i <= n; i++) rest.insert(i);
  for(int i = 1; i <= n; i++) {
    if(!rest.count(i)) continue;

    rest.erase(i);
    comp++;

    queue<int> Q;
    Q.push(i);
    while(Q.size()) {
      int u = Q.front(); Q.pop();

      vector<int> nbh(rest.size()); // neighbourhood
      auto it = set_difference(all(rest), all(g[u]), nbh.begin());
      nbh.resize(it-nbh.begin());

      for(int v: nbh) rest.erase(v), Q.push(v);
    }
  }

  printf("%d\n", comp-1);

  return 0;
}
