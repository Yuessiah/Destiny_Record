#include<bits/stdc++.h>
using namespace std;

int t, n, m;

int main()
{
  scanf("%d", &t);

  while(t--) {
    scanf("%d%d", &n, &m);

    int a, b, c, d;
    bool ok = false;
    while(n--) {
      scanf("%d%d", &a, &b);
      scanf("%d%d", &c, &d);
      if(b == c) ok = true;
    }

    puts((!(m%2) && ok)? "YES" : "NO");
  }

  return 0;
}
