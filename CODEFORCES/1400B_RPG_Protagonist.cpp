#include<bits/stdc++.h>
using namespace std;

int t, p, f, cnts, cntw, s, w;

int main()
{
  cin >> t;
  while(t--) {
    cin >> p >> f;
    cin >> cnts >> cntw;
    cin >> s >> w;

    if(s > w) swap(s, w), swap(cnts, cntw);

    int ans = 0;
    for(int ns = 0; ns <= cnts; ns++) {
      int x1 = min(p/s, ns);
      int x2 = min((p-x1*s)/w, cntw);
      int x3 = min(f/s, cnts-x1);
      int x4 = min((f-x3*s)/w, cntw-x2);
      ans = max(ans, x1+x2+x3+x4);
    }

    cout << ans << endl;
  }

  return 0;
}
