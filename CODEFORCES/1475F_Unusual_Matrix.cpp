#include<bits/stdc++.h>
using namespace std;

int t, n, b;
char x;
vector<vector<int>> a, c;

int main()
{
  cin >> t;
  while(t--) {
    cin >> n;

    a.assign(n, vector<int>(n));
    for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++)
        cin >> x, a[i][j] = x-'0';

    c.assign(n, vector<int>(n));
    for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++)
        cin >> x, c[i][j] = a[i][j] ^ x-'0';

    bool ok = true;
    for(int i = 0; i < n; i++) {
      bool dif = true, sam = true;
      for(int j = 0; j < n; j++) {
        if(c[i][j] == c[0][j]) dif = false;
        if(c[i][j] != c[0][j]) sam = false;
      }

      if(!sam && !dif) ok = false;
    }

    puts(ok? "YES" : "NO");
  }

  return 0;
}
