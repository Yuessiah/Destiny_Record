#include<bits/stdc++.h>
using namespace std;
typedef long long Int;

long double X, Y, R;

int main()
{
  cin >> X >> Y >> R;
  X -= floor(X), Y -= floor(Y);

  Int ans = 0;
  for(int i = Y-R; i <= Y+R; i++) {
    {
      int l = X-R, r = X+1;
      while(l < r) {
        int m = floor((l+r)/2.0);
        if((X-m)*(X-m) + (Y-i)*(Y-i) <= R*R) r = m;
        else l = m+1;
      }

      ans -= l;
    }
    {
      int l = X-1, r = X+R;
      while(l < r) {
        int m = ceil((l+r)/2.0);
        if((X-m)*(X-m) + (Y-i)*(Y-i) <= R*R) l = m;
        else r = m-1;
      }

      ans += r+1;
    }
  }

  cout << ans << endl;

  return 0;
}
