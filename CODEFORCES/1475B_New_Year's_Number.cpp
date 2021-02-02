#include<bits/stdc++.h>
using namespace std;

int t;
long long n;

int main()
{
  cin >> t;
  while(t--) {
    cin >> n;
    if(n/2020 >= n%2020) puts("YES");
    else puts("NO");
  }

  return 0;
}
