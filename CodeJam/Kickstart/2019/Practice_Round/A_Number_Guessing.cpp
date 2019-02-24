#include<bits/stdc++.h>
using namespace std;

int t, a, b, n;
string s;

int main()
{
  cin >> t;
  while(t--) {
    cin >> a >> b >> n;

    while(n--) {
      int m = a + ceil((b-a)/2.0);

      cout << m << endl;
      cin >> s;

      if(s == "TOO_SMALL") a = m;
      if(s == "TOO_BIG") b = m-1;
      if(s == "CORRECT") break;
      if(s == "WRONG_ANSWER") break;
    }
  }

  return 0;
}
