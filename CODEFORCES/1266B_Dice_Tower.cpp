#include<bits/stdc++.h>
using namespace std;

int t;
long long x;

int main()
{
  scanf("%d", &t);
  while(t--) {
    scanf("%lld", &x);
    if(x <= 14) puts("NO");
    else puts((x%14<=6 && x%14>=1)? "YES" : "NO");
  }

  return 0;
}
