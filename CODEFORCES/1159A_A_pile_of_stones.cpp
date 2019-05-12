#include<bits/stdc++.h>
using namespace std;

int n;
string s;

int main()
{
  cin >> n >> s;

  int cnt = 0;
  for(int i = 0; i < n; i++) {
    if(s[i] == '+') cnt++;
    if(s[i] == '-') cnt--;

    if(cnt < 0) cnt = 0;
  }

  cout << cnt;

  return 0;
}
