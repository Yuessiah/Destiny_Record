#include<bits/stdc++.h>
using namespace std;

int const maxp = 510;

struct edge { int u, v; double dist; };
struct point { double x, y; } C[maxp];
int S, P, k, group[maxp];

double dist(point u, point v) {
  double x = u.x - v.x, y = u.y - v.y;
  return sqrt(x*x + y*y);
}

int Find(int u)
  { return (group[u] == u)? u : group[u] = Find(group[u]); }

void Union(int a, int b)
  { group[Find(a)] = Find(b); }

int main()
{
  int N;
  scanf("%d", &N);

  while(N--) {
    scanf("%d%d", &S, &P);

    vector<edge> E;
    for(int i = 0; i < P; i++) {
      group[i] = i;

      scanf("%lf%lf", &C[i].x, &C[i].y);
      for(int j = 0; j < i; j++) E.push_back({j, i, dist(C[i], C[j])});
    }

    sort(E.begin(), E.end(), [&](edge A, edge B) { return A.dist < B.dist; });

    vector<double> D;
    for(edge e: E) {
      int a = Find(e.u), b = Find(e.v);
      if(a != b) {
        D.push_back(e.dist);
        Union(e.u, e.v);
      }
    }

    printf("%.2lf\n", D[P-S-1]);
  }

  return 0;
}
