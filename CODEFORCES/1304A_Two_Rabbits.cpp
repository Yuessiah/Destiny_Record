#include<bits/stdc++.h>
using namespace std;

int t, x, y, a, b;

int main()
{
  scanf("%d", &t);
  while(t--) {
    scanf("%d%d%d%d", &x, &y, &a, &b);
    y -= x;

    if(y%(a+b) == 0) printf("%d\n", y/(a+b));
    else printf("%d\n", -1);
  }

  return 0;
}
