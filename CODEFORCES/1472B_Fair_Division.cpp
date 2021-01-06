#include<bits/stdc++.h>
using namespace std;

int t, n, a;

int main()
{
  cin >> t;

  while(t--) {
    cin >> n;

    int one = 0, two = 0;
    while(n--) {
      cin >> a;
      if(a == 1) one++;
      if(a == 2) two++;
    }

    if(!(one%2) && ((two%2 && one >= 2) || !(two%2))) puts("YES");
    else puts("NO");
  }

  return 0;
}
