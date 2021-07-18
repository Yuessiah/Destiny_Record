#include<bits/stdc++.h>
using namespace std;

int constexpr maxn = 2e5 + 10;

int n, x, p[maxn];

int main()
{
  cin >> n >> x;
  for(int i = 0; i < n; i++) cin >> p[i];

  sort(p, p+n);
  int ans = 0;
  for(int i = n-1, j = 0; i >= j; i--) {
    if(p[i]+p[j] <= x) j++;
    ans++;
  }

  cout << ans << endl;

  return 0;
}
