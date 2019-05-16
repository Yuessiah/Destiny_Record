#include<bits/stdc++.h>
using namespace std;

int n, x, y;
string d;

int main()
{
  cin >> n >> x >> y >> d;

  reverse(d.begin(), d.end());

  int cnt = 0;
  for(x--; x >= 0; x--) {
    if(x != y && d[x] != '0') cnt++;
    if(x == y && d[x] != '1') cnt++;
  }

  cout << cnt;

  return 0;
}
