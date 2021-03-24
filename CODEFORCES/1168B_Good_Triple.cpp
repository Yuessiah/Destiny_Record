#include<bits/stdc++.h>
using namespace std;

string s;

int main()
{
  cin >> s;

  long long n = s.length(), r = n, ans = 0;
  for(int l = n-1; l >= 0; l--) {
    for(int k = 1; l+2*k < r; k++) {
      if(s[l] != s[l+k] || s[l] != s[l+2*k]) continue;
      r = l+2*k;
    }

    ans += n - r;
  }

  cout << ans << endl;

  return 0;
}
