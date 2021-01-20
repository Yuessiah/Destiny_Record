#include<bits/stdc++.h>
using namespace std;
typedef long long Int;

int const maxn = 2e5 + 10;

int t, n, a[maxn];

int main()
{
  cin >> t;
  while(t--) {
    cin >> n;

    Int sum = 0;
    for(int i = 0; i < n; i++) {
      cin >> a[i];
      if(i) sum += abs(a[i]-a[i-1]);
    }

    Int ans = sum - max(abs(a[n-1]-a[n-2]), abs(a[1]-a[0]));
    for(int i = 1; i < n-1; i++)
      ans = min(ans, sum - abs(a[i]-a[i-1]) - abs(a[i+1]-a[i]) + abs(a[i+1]-a[i-1]));

    cout << ans << endl;
  }

  return 0;
}
