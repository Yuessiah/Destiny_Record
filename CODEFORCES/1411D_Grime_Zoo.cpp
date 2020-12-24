#include<bits/stdc++.h>
using namespace std;
typedef long long Int;

string s;
int x, y;

int main()
{
  cin >> s >> x >> y;

  int n = s.length(), c = y < x;
  if(!c) swap(y, x);

  Int sum = 0, t = 0;
  for(int i = 0; i < n; i++) {
    if(s[i] == '0'+c) sum += (i-t)*x, t++;
    else sum += t*y;
  }

  Int ans = sum;
  for(int i = 0; i < n; i++) {
    if(s[i] != '?') continue;
    ans = min(ans, sum += (i-t)*x + (n-1-i-t)*y);
    t++;
  }

  cout << ans << endl;

  return 0;
}
