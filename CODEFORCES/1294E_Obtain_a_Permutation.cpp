#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> a;

int main()
{
  scanf("%d%d", &n, &m);
  a.assign(n, vector<int>(m));

  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++) scanf("%d", &a[i][j]), a[i][j]--;

  int ans = 0;
  for(int j = 0; j < m; j++) {
    vector<int> cnt(n, 0);
    for(int i = 0; i < n; i++) {
      if(a[i][j]%m != j || a[i][j]/m >= n) continue;
      cnt[(i-a[i][j]/m + n) % n]++;
    }

    int best = n;
    for(int d = 0; d < n; d++) best = min(best, d + n-cnt[d]);
    ans += best;
  }

  printf("%d\n", ans);

  return 0;
}
