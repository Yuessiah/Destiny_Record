#include<bits/stdc++.h>
using namespace std;

int t, w, h, n;

int main()
{
  cin >> t;
  while(t--) {
    cin >> w >> h >> n;

    int cw = 1, ch = 1;
    while(w%2 == 0) cw*=2, w/=2;
    while(h%2 == 0) ch*=2, h/=2;

    puts(cw*ch >= n? "YES" : "NO");
  }

  return 0;
}
