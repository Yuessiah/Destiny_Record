#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;

int const maxn = 5010;

struct node {
  int id, w;
  node(int id, int w): id(id), w(w){}
  bool operator<(node const &rhs) const
    { return w > rhs.w; }
};

int R, N, A, B, D;
vector<node> E[maxn];

int main()
{
  scanf("%d%d", &N, &R);

  for(int i = 0; i < R; i++) {
    scanf("%d%d%d", &A, &B, &D);
    E[A].push_back({B, D});
    E[B].push_back({A, D});
  }

  priority_queue<node> Q;
  int d1[maxn], d2[maxn];

  memset(d1, 0x3f, sizeof d1);
  memset(d2, 0x3f, sizeof d2);
  Q.push({1, d1[1] = 0});

  while(!Q.empty()) {
    node u = Q.top(); Q.pop();

    for(int i = 0; i < (int)E[u.id].size(); i++) {
      node v = E[u.id][i];
      int ud = u.w + v.w;

      if(ud < d1[v.id]) {
        Q.push({v.id, ud});
        swap(d1[v.id], ud);
      }

      if(ud < d2[v.id] && ud > d1[v.id])
        Q.push({v.id, d2[v.id] = ud});
    }
  }

  printf("%d\n", d2[N]);

  return 0;
}
