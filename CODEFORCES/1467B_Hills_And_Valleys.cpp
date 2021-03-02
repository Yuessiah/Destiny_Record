#include<bits/stdc++.h>
using namespace std;

int constexpr maxn = 3e5 + 10;

int t, n, a[maxn];

bool hv(int i) {
  if(i > 0 && i < n-1) {
    if(a[i] > max(a[i-1], a[i+1])) return true;
    if(a[i] < min(a[i-1], a[i+1])) return true;
  }
  return false;
}

int main()
{
  cin >> t;
  while(t--) {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];

    int sum = 0;
    for(int i = 0; i < n; i++) if(hv(i)) sum++;

    int ans = sum;
    for(int i = 1; i < n-1; i++) {
      bool c1 = hv(i-1), c2 = hv(i), c3 = hv(i+1);
      int ai = a[i];
      a[i] = a[i-1], ans = min(ans, sum -c1-c2-c3 +hv(i-1)+hv(i)+hv(i+1));
      a[i] = a[i+1], ans = min(ans, sum -c1-c2-c3 +hv(i-1)+hv(i)+hv(i+1));
      a[i] = ai;
    }

    cout << ans << endl;
  }

  return 0;
}
