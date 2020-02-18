#include<bits/stdc++.h>
using namespace std;

int const maxn = 1e5 + 10;

int t, n;
vector<int> a;

int m(int k) {
  vector<int> b(a);
  int mx = 0; // maximum of absolute differences

  for(int i = 0; i+1 < n; i++) {
    if(b[ i ] == -1) b[ i ] = k;
    if(b[i+1] == -1) b[i+1] = k;

    mx = max(mx, abs(b[i] - b[i+1]));
  }

  return mx;
}

int main()
{
  scanf("%d", &t);

  while(t--) {
    scanf("%d", &n);

    a.resize(n);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);

    int l = 0, r = 1e9+10;
    while(r - l > 2) {
      int k1 = l + (r-l)/3, k2 = r - (r-l)/3;
      if(m(k1) > m(k2)) l = k1;
      else r = k2;
    }

    if(m(l) < m(l+1)) printf("%d %d\n", m(l), l);
    else printf("%d %d\n", m(l+1), l+1);
  }

  return 0;
}
