#include<bits/stdc++.h>
using namespace std;

int t, n;
string s;

int main()
{
  cin >> t;
  while(t--) {
    cin >> n >> s;

    int e = 0;
    for(int i = n-1; i >= 0; i--) {
      if(s[i] != ')') break;
      e++;
    }

    if(e > n-e) puts("Yes");
    else puts("No");
  }

  return 0;
}
