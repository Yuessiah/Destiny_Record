#include<bits/stdc++.h>
using namespace std;

int n;

int main()
{
  scanf("%d", &n);

  int d, one, zero;
  for(int i = 1; i <= n; i++) {
    scanf("%d", &d);
    if(d) one = i;
    else zero = i;
  }

  printf("%d\n", min(one, zero));

  return 0;
}
