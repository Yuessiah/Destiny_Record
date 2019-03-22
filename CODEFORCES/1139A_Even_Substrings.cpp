#include<bits/stdc++.h>
using namespace std;

int n;
char c;

int main()
{
  cin >> n;

  long long ans = 0;
  for(int i = 1; i <= n; i++) {
    cin >> c;
    if((c-'0')%2 == 0) ans += i;
  }

  cout << ans << endl;

  return 0;
}
