#include<bits/stdc++.h>
using namespace std;

int constexpr maxn = 25;

int n, a[maxn], c[maxn];

int main()
{
  cin >> n;
  for(int i = 0; i < n; i++) cin >> a[i], c[i] = a[i];
  sort(c, c+n);

  for(int i = 0; i < n; i++) {
    int p = lower_bound(c, c+n, a[i]) - c;
    cout << c[(p+1)%n] << ' ';
  }
  cout << endl;

  return 0;
}
