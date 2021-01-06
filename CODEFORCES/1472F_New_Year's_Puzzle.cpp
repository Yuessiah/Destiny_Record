#include<bits/stdc++.h>
using namespace std;

int const maxm = 2e5 + 10;

int t, n, m;
struct grid { int r, c; } g[maxm];

int main()
{
  cin >> t;
  while(t--) {
    cin >> n >> m;
    for(int i = 0; i < m; i++) cin >> g[i].r >> g[i].c;

    sort(g, g+m, [](grid a, grid b) { return a.c < b.c; });

    bool ok = m%2 == 0;
    for(int i = 1; i < m; i+=2) {
      if(i >= 2 && g[i-1].c == g[i-2].c) ok = false;
      if((g[i].c - g[i-1].c + (g[i].r != g[i-1].r)) % 2 == 0) ok = false;
    }

    puts(ok? "YES" : "NO");
  }

  return 0;
}
