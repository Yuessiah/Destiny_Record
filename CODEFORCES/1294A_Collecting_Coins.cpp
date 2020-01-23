#include<bits/stdc++.h>
using namespace std;

int t, a, b, c, n;

int main()
{
  scanf("%d", &t);
  while(t--) {
    scanf("%d%d%d%d", &a, &b, &c, &n);
    n += a + b + c;

    if(a > n/3 || b > n/3 || c > n/3 || n%3) puts("NO");
    else puts("YES");
  }

  return 0;
}
