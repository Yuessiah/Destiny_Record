#include<bits/stdc++.h>
using namespace std;

int const maxn = 2e5 + 10;

int q, n, p[maxn], done[maxn], a[maxn];

int main() {
  scanf("%d", &q);

  while(q--) {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &p[i]);

    memset(done, false, sizeof done);
    for(int i = 1; i <= n; i++) {
      if(done[i]) continue;

      int cnt = 0, x = i;
      vector<int> xs;
      do {
        xs.push_back(x = p[x]);
        done[x] = true, cnt++;
      } while(x != i);

      for(int x: xs) a[x] = cnt;
    }

    for(int i = 1; i <= n; i++) printf("%d ", a[i]);
    putchar('\n');
  }

  return 0;
}
