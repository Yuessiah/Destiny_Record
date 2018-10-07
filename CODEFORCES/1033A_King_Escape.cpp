#include<bits/stdc++.h>
using namespace std;

int n, a1, a2, b1, b2, c1, c2;

int main()
{
  scanf("%d", &n);
  scanf("%d%d", &a1, &a2);
  scanf("%d%d", &b1, &b2);
  scanf("%d%d", &c1, &c2);

  if(((b1 < a1 && a1 < c1) || (c2 < a2 && a2 < b2)) ||
      ((b1 > a1 && a1 > c1) || (c2 < a2 && a2 < b2)) ||
      ((b1 < a1 && a1 < c1) || (c2 > a2 && a2 > b2)) ||
      ((b1 > a1 && a1 > c1) || (c2 > a2 && a2 > b2))) puts("NO");
  else puts("YES");

  return 0;
}
