#include<bits/stdc++.h>
using namespace std;
typedef long long Int;

int constexpr maxn = 3e5 + 10;

int T, n;
Int a[maxn], b[maxn];

int main()
{
  ios::sync_with_stdio(false), cin.tie(0);

  cin >> T;
  while(T--) {
    cin >> n;
    for(int i = 0; i < n; i++)
      cin >> a[i] >> b[i];

    Int sum = 0, add = a[0];
    for(int i = 0; i < n; i++) {
      sum += max(a[i]-b[(i-1+n)%n], 0ll);
      add = min({add, a[i], b[(i-1+n)%n]});
    }

    cout << (sum += add) << endl;
  }

  return 0;
}
