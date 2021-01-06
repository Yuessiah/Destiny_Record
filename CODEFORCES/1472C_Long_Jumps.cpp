#include<bits/stdc++.h>
using namespace std;

int const maxn = 2e5 + 10;

int t, n, a;

int main()
{
  cin >> t;

  while(t--) {
    cin >> n;

    int s[maxn] = {}, ans = 0;
    for(int i = 0; i < n; i++) {
      cin >> a;

      if(i+a >= n) ans = max(ans, s[i] + a);
      else s[i+a] = max(s[i+a], s[i] + a);
    }

    cout << ans << endl;
  }

  return 0;
}
