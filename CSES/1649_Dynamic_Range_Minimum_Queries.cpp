#include<bits/stdc++.h>
using namespace std;

int constexpr maxn = 2e5 + 10;

int n, q, x, cmd, k, u, a, b, mi[1<<19]; // 19 = ceil(log2(maxn))+1

void edit(int i, int v, int p=1, int L=1, int R=n+1) {
  if(i < L || R <= i) return;
  if(R-L == 1) {
    mi[p] = v;
    return;
  }

  int M = (L+R)/2;
  edit(i, v, p*2+0, L, M);
  edit(i, v, p*2+1, M, R);

  mi[p] = min(mi[p*2+0], mi[p*2+1]);
}

int query(int l, int r, int p=1, int L=1, int R=n+1) {
  if(R <= l || r <= L) return 0x3f3f3f3f;
  if(l <= L && R <= r) return mi[p];

  int M = (L+R)/2;
  return min(query(l, r, p*2+0, L, M), query(l, r, p*2+1, M, R));
}

int main()
{
  cin.tie(0), ios::sync_with_stdio(false);

  memset(mi, 0x3f, sizeof(mi));

  cin >> n >> q;

  for(int i = 1; i <= n; i++) {
    cin >> x;
    edit(i, x);
  }

  while(q--) {
    cin >> cmd;
    switch(cmd) {
      case 1:
        cin >> k >> u;
        edit(k, u);
        break;
      case 2:
        cin >> a >> b;
        cout << query(a, b+1) << endl;
        break;
    }
  }

  return 0;
}
