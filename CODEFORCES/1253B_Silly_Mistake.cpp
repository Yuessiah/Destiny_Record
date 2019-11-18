#include<bits/stdc++.h>
using namespace std;

int n, a;
set<int> ent, vis; // enter, visit

void error()
  { puts("-1"); exit(0); }

int main()
{
  scanf("%d", &n);

  vector<int> ans;
  for(int i = 0; i < n; i++) {
    scanf("%d", &a);

    if(a > 0) {
      if(vis.count(a)) error();
      ent.insert(a);
      vis.insert(a);
    } else {
      if(!ent.count(-a)) error();
      ent.erase(-a);
    }

    if(ent.empty()) {
      ans.push_back(2*vis.size());
      vis.clear();
    }
  }

  if(ent.size()) error();

  printf("%d\n", ans.size());
  for(int it: ans) printf("%d ", it);
  putchar('\n');

  return 0;
}
