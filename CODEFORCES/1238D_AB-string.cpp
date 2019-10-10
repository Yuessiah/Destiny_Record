#include<bits/stdc++.h>
using namespace std;
typedef long long Int;

Int n;
string s;

int main()
{
  cin >> n >> s;

  Int good = n*(n-1)/2;
  for(int t = 0; t < 2; t++) {
    for(int i = 0, j = 0; i < n; i=j) {
      while(j < n && s[i] == s[j]) j++;
      if(j != n) good -= j - i - t;
    }

    reverse(s.begin(), s.end());
  }

  cout << good << endl;

  return 0;
}
