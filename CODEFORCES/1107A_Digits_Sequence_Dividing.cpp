#include<bits/stdc++.h>
using namespace std;

int main()
{
  int q, n;
  cin >> q;
  while(q--) {
    cin >> n;

    string s;
    cin >> s;

    if(s.length() > 2 || s[0] < s[1]) {
      cout << "YES" << endl
        << 2 << endl
        << s[0] << ' ' << s.substr(1, n-1) << endl;
    } else cout << "NO" << endl;
  }

  return 0;
}
