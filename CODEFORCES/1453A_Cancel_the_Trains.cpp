#include<bits/stdc++.h>
using namespace std;

int t, n, m, a;
bool s[110];

int main()
{
  cin >> t;
  while(t--) {
    cin >> n >> m;

    memset(s, false, sizeof s);
    for(int i = 0; i < n; i++) cin >> a, s[a] = true;

    int cnt = 0;
    for(int i = 0; i < m; i++) {
      cin >> a;
      if(s[a]) cnt++;
    }

    printf("%d\n", cnt);
  }
}
