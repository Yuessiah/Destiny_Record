#include<bits/stdc++.h>
using namespace std;

int t;
long long n;

int main()
{
  cin >> t;
  while(t--) {
    cin >> n;
    while(n%2 == 0) n /= 2;
    cout << (n>1? "YES" : "NO") << endl;
  }

  return 0;
}
