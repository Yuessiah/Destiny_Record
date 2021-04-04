#include<bits/stdc++.h>
using namespace std;

int constexpr maxm = 2e5 + 10;

int t, n, m, a, b, s[maxm];

bool chk(int j) {
  int last = 0;
  for(int i = j, t = 1; i >= 0; i--)
    last = max(last, s[i] + (t++));

  int d = (b>a)? b-1 : n-b;
  return (last <= d) && (j+1 < abs(b-a));
}

int main()
{
  cin >> t;
  while(t--) {
    cin >> n >> m >> a >> b;
    for(int i = 0; i < m; i++) cin >> s[i];

    sort(s, s+m);
    int l = 0, r = m;
    while(l != r) {
      int j = (l+r)/2;
      if(chk(j)) l = j+1;
      else r = j;
    }

    cout << l << endl;
  }

  return 0;
}
