#include<bits/stdc++.h>
using namespace std;

typedef long long Int;

int t;
Int n;

int main()
{
  cin >> t;
  while(t--) {
    cin >> n;

    for(Int d = n; d <= 1e18; d++) {
      Int p = d;
      bool ok = true;

      while(p) {
        Int x = p%10;
        p /= 10;
        if(x == 0) continue;

        if(d%x != 0) ok = false;
      }

      if(ok) {
        cout << d << endl;
        break;
      }
    }
  }

  return 0;
}
