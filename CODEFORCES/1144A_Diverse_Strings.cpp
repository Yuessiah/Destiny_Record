#include<bits/stdc++.h>
using namespace std;

int n;
string s;

int main()
{
  cin >> n;
  while(n--) {
    cin >> s;
    sort(s.begin(), s.end());

    bool ok = true;
    for(int i = 1; i < s.length(); i++)
      if(s[i-1]+1 != s[i]) { ok = false; break; }

    puts(ok? "Yes" : "No");
  }

  return 0;
}
