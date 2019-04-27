#include<bits/stdc++.h>
using namespace std;

int n;
string s;

int main()
{
  cin >> n >> s;

  int mi = n-1;
  for(int i = n-1; i >= 0; i--) {
    if(s[i] > s[mi]) {
      cout << "YES" << '\n';
      cout << i+1 << ' ' << mi+1 << endl;
      return 0;
    } else mi = i;
  }

  cout << "NO" << endl;

  return 0;
}
