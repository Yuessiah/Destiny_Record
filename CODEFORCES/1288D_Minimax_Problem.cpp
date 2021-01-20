#include<bits/stdc++.h>
using namespace std;

int const maxn = 3e5 + 10;

int n, m, a[maxn][9];

int main()
{
  cin >> n >> m;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++) cin >> a[i][j];

  int l = 0, r = 1e9+1, ans_i, ans_j;
  while(l != r) {
    int x = l+(r-l)/2;

    vector<int> msk(1 << m, -1);
    for(int i = 0; i < n; i++) {
      int cur = 0;
      for(int j = 0; j < m; j++)
        cur |= (a[i][j] >= x) << j;
      msk[cur] = i;
    }

    bool ok = false;
    for(int p = 0; p < (1<<m); p++)
      for(int q = 0; q < (1<<m); q++)
        if((p|q) == (1<<m)-1 && ~msk[p] && ~msk[q]) {
          ok = true;
          ans_i = msk[p];
          ans_j = msk[q];
          break;
        }

    if(ok) l = x+1;
    else r = x;
  }

  cout << ans_i+1 << ' ' << ans_j+1 << endl;

  return 0;
}
