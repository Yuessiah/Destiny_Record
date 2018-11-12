#include<bits/stdc++.h>
using namespace std;

int n;
string s;

int main()
{
  cin >> n >> s;

  bool one = false;
  for(int i = 0, l = s.size(); i < l; i++) {
    if(!one) {
      if(i < l-1 && s[i] > s[i+1]) {
        one = true;
        continue;
      }

      if(i == l-1) continue;
    }

    cout << s[i];
  }

  return 0;
}
