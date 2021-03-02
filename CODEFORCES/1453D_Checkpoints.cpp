#include<bits/stdc++.h>
using namespace std;
typedef long long Int;

int t;
Int k;

int main()
{
  cin >> t;
  while(t--) {
    cin >> k;
    if(k&1) { puts("-1"); continue; }

    vector<int> s;
    while(k) {
      Int x = 2, cnt = 1;
      while(2*(x+1) < k) x = 2*(x+1), cnt++;
      k -= x;
      s.push_back(cnt);
    }

    cout << accumulate(s.begin(), s.end(), 0) << endl;
    for(int cnt: s) {
      cout << 1 << ' ';
      while(--cnt) cout << 0 << ' ';
    }
    cout << endl;
  }

  return 0;
}
