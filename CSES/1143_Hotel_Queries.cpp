#include<bits/stdc++.h>
using namespace std;

int constexpr maxn = 2e5 + 10;

int n, m, h[maxn], r, mx[1<<19]; // 19 = ceil(log2(maxn))+1

void edit(int i, int v, int p=1, int L=0, int R=n) {
  if(i < L || R <= i) return;
  if(R-L == 1) {
    h[i] = mx[p] = v;
    return;
  }

  int M = (L+R)/2;
  edit(i, v, p*2+0, L, M);
  edit(i, v, p*2+1, M, R);

  mx[p] = max(mx[p*2+0], mx[p*2+1]);
}

int query(int v, int p=1, int L=0, int R=n) {
  if(R-L == 1) return L;

  int M = (L+R)/2;
  if(mx[p*2+0] >= v) return query(v, p*2+0, L, M);
  else return query(v, p*2+1, M, R);
}

int main()
{
  cin.tie(0), ios::sync_with_stdio(false);

  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    cin >> h[i];
    edit(i, h[i]);
  }

  while(m--) {
    cin >> r;
    if(r > mx[1]) cout << "0 ";
    else {
      int j = query(r);
      edit(j, h[j]-r);
      cout << j+1 << ' ';
    }
  }
  cout << endl;

  return 0;
}
