#include<bits/stdc++.h>
using namespace std;

int const maxm = 22;

int n, m, a[maxm], b[maxm];
set<set<int>> used;

int main()
{
  scanf("%d%d", &n, &m);
  for(int i = 0; i < m; i++) scanf("%d%d", &a[i], &b[i]);

  int best = 0;
  if(n != 7) {
    for(int i = 0; i < m; i++) used.insert({a[i], b[i]});
    best = used.size();
  } else {
    for(int i = 1; i <= 7; i++) {
      for(int j = i+1; j <= 7; j++) {
        int c[8] = {};
        c[i] = c[j] = 1;
        for(int k = 1, p = 2; k <= 7; k++) if(c[k] != 1) c[k] = p++;

        used.clear();
        for(int k = 0; k < m; k++) used.insert({c[a[k]], c[b[k]]});
        best = max(best, (int)used.size());
      }
    }
  }

  printf("%d\n", best);

  return 0;
}
