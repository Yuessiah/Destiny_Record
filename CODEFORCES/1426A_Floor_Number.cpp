#include<bits/stdc++.h>
using namespace std;

int t, n, x;

int main()
{
  scanf("%d", &t);

  while(t--) {
    scanf("%d%d", &n, &x);
    if(n <= 2) puts("1");
    else {
      n -= 2;
      printf("%d\n", n/x + !!(n%x) + 1);
    }
  }

  return 0;
}
