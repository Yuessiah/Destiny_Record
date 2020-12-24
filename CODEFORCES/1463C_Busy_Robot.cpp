#include<bits/stdc++.h>
using namespace std;
typedef long long Int;

int const maxn = 1e5 + 10;

Int T, n, t[maxn], x[maxn];

int main()
{
  cin >> T;
  while(T--) {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> t[i] >> x[i];
    t[n] = 3e9-1;

    Int suc = 0, goal = 0, at = 0;
    for(int i = 0; i < n; i++) {
      if(i) {
        Int nxt = at + (t[i]-t[i-1])*((goal>at)-(goal<at));
        at = abs(nxt-at) > abs(goal-at)? goal : nxt;
      }
      if(at == goal) goal = x[i];

      Int nxt = at + (t[i+1]-t[i])*((goal>at)-(goal<at));
      if(abs(nxt-at) > abs(goal-at)) nxt = goal;

      if(nxt >= x[i] && x[i] >= at) suc++;
      else if(nxt <= x[i] && x[i] <= at) suc++;
    }

    cout << suc << endl;
  }

  return 0;
}
