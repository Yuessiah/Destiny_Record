#include<bits/stdc++.h>
using namespace std;

int const maxd = 210;
int const INF = 0x3f3f3f3f;

struct node {
  int j[3], total; // j := jug
  bool operator<(node const &rhs) const
    { return total > rhs.total; }
};

int v[3], d, ans[maxd];
bool vis[maxd][maxd];

void update_ans(node n) {
  for(int i = 0; i < 3; i++)
    ans[n.j[i]] = min(ans[n.j[i]], n.total);
}

int main()
{
  int T;
  scanf("%d", &T);

  while(T--) {
    scanf("%d%d%d%d", &v[0], &v[1], &v[2], &d); // a, b, c volume

    memset(vis, false, sizeof vis);
    memset(ans, 0x3f, sizeof ans);
    ans[0] = 0;
    priority_queue<node> PQ;
    PQ.push({0, 0, v[2], 0}); //root

    while(!PQ.empty()) {
      node u = PQ.top(); PQ.pop();

      update_ans(u);
      if(ans[d] != INF) break;

      if(vis[u.j[0]][u.j[1]]) continue;
      vis[u.j[0]][u.j[1]] = true;

      for(int s = 0; s < 3; s++)
        for(int t = 0; t < 3; t++) {
          if(s == t) continue;
          int pour = min(u.j[s], v[t] - u.j[t]);

          node v = u;
          v.j[s] -= pour;
          v.j[t] += pour;
          v.total += pour;

          if(vis[v.j[0]][v.j[1]]) continue;
          PQ.push(v);
        }
    }

    for(int _d = d; _d >= 0; _d--)
      if(ans[_d] != INF) {
        printf("%d %d\n", ans[_d], _d);
        break;
      }
  }

  return 0;
}
