#include<bits/stdc++.h>
using namespace std;

int n;
string s;

int main()
{
  cin >> n >> s;

  string t;
  for(int i = 0; i < n-1; i++)
    if(s[i] != s[i+1]) t += s.substr(i, 2), i++;

  cout << s.size() - t.size() << endl;
  cout << t << endl;

  return 0;
}
