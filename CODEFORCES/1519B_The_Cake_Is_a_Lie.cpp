#include<bits/stdc++.h>
using namespace std;

int t, n, m, k;

int main()
{
  cin >> t;
  while(t--) {
    cin >> n >> m >> k;
    puts((n-1+(m-1)*n == k)? "YES" : "NO");
  }

  return 0;
}
