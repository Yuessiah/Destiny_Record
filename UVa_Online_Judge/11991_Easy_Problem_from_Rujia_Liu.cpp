#include<bits/stdc++.h>
using namespace std;

int n, m, v, k;
map<int, vector<int> > pos;

int main()
{
  while(~scanf("%d%d", &n, &m)) {
    pos.clear();

    for(int i = 1; i <= n; i++) {
      scanf("%d", &v);
      pos[v].push_back(i);
    }

    while(m--) {
      scanf("%d%d", &k, &v);
      if(pos[v].size() < k) puts("0");
      else printf("%d\n", pos[v][k-1]);
    }
  }

  return 0;
}
