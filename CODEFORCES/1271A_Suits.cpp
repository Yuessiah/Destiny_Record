#include<bits/stdc++.h>
using namespace std;

int a, b, c, d, e, f;

int main()
{
  scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f);

  if(e > f) {
    int x = min(a, d);
    d -= x;

    int y = min({b, c, d});

    printf("%d\n", e*x + f*y);
  } else {
    int y = min({b, c, d});
    d -= y;

    int x = min(a, d);

    printf("%d\n", e*x + f*y);
  }

  return 0;
}
