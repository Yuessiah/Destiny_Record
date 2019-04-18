#include<bits/stdc++.h>
using namespace std;

int const maxn = 510;

int n, m, a[maxn][maxn];

int main()
{
  scanf("%d%d", &n, &m);

  int xr = 0;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) scanf("%d", &a[i][j]);
    xr ^= a[i][1];
  }

  vector<int> res;
  bool tak = xr > 0, fir = false;
  for(int i = 1; i <= n; i++) {
    for(int j = 2; j <= m && !tak; j++)
      if(a[i][j] != a[i][1]) res.push_back(j), fir = tak = true;

    if(fir) fir = false;
    else res.push_back(1);
  }

  if(tak) {
    puts("TAK");
    for(int i = 0; i < n; i++) printf("%d ", res[i]);
    putchar('\n');
  } else puts("NIE");

  return 0;
}
