#include<bits/stdc++.h>
using namespace std;

int t;
long long x, y;

int main()
{
  scanf("%d", &t);
  while(t--) {
    scanf("%lld%lld", &x, &y);
    puts((x-y != 1)? "YES" : "NO");
  }

  return 0;
}
