#include<bits/stdc++.h>
using namespace std;

int const maxn = 1e5 + 10;

int n, a[maxn], b[maxn];
long long ans;

void merge_sort(int l, int r) {
  if(r-l <= 1) return;

  int m = (l+r)/2;
  merge_sort(l, m);
  merge_sort(m, r);

  copy(a+l, a+r, b+l);
  int p = l, q = m, i = l;

  while(i < r) {
    if((p != m && b[p] <= b[q]) || q == r) a[i++] = b[p++];
    else {
      a[i++] = b[q++];
      ans += (m-p);
    }
  }
}

int main()
{
  int kase = 0;

  while(scanf("%d", &n) && n) {
    ans = 0;

    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    merge_sort(0, n);

    printf("Case #%d: %lld\n", ++kase, ans);
  }

  return 0;
}
