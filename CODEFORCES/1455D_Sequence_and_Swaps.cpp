#include<bits/stdc++.h>
using namespace std;

int const maxn = 510;

int t, n, x, a[maxn];

int main()
{
  cin >> t;
  while(t--) {
    cin >> n >> x;
    for(int i = 0; i < n; i++) cin >> a[i];

    int ans = 0;
    for(int i = 0; i < n; i++) {
      if(is_sorted(a+i, a+n)) break;
      if(x < a[i]) swap(x, a[i]), ans++;
    }

    printf("%d\n", is_sorted(a, a+n)? ans : -1);
  }

  return 0;
}
