#include<bits/stdc++.h>
using namespace std;

int const maxa = 1010, maxn = 25;

struct element {
  int a, t;
  bool operator<(element const &rhs) const
    { return t < rhs.t; }
};

int n, C[maxa], mat[maxn][maxn];
priority_queue<element> E;

int main()
{
  scanf("%d", &n);

  for(int i = 0, a; i < n*n; i++) scanf("%d", &a), C[a]++;
  for(int a = 1; a < maxa; a++) if(C[a]) E.push({a, C[a]});

  for(int i = 0; i < (n/2) * (n/2); i++) {
    element e = E.top(); E.pop();

    if(e.t >= 4) {
      e.t -= 4;

      int r = i/(n/2), c = i%(n/2);
      mat[r][c] = e.a;
      mat[r][n-1 - c] = e.a;
      mat[n-1 - r][c] = e.a;
      mat[n-1 - r][n-1 - c] = e.a;

      E.push(e);
    } else { puts("NO"); return 0; }
  }

  if(n&1) {
    for(int c = 0; c < n/2; c++) {
      element e = E.top(); E.pop();
      if(e.t >= 2) {
        e.t -= 2;
        mat[n/2][c] = mat[n/2][n-1 - c] = e.a;

        E.push(e);
      } else { puts("NO"); return 0; }
    }

    for(int r = 0; r < n/2; r++) {
      element e = E.top(); E.pop();
      if(e.t >= 2) {
        e.t -= 2;
        mat[r][n/2] = mat[n-1 - r][n/2] = e.a;

        E.push(e);
      } else { puts("NO"); return 0; }
    }

    mat[n/2][n/2] = E.top().a;
  }

  puts("YES");
  for(int r = 0; r < n; r++) {
    for(int c = 0; c < n; c++) printf("%d ", mat[r][c]);
    putchar('\n');
  }

  return 0;
}
