#include<bits/stdc++.h>
using namespace std;

int n, a;

int main()
{
  scanf("%d", &n);

  int neg = 0, pos = 0;
  for(int i = 0; i < n; i++) {
    scanf("%d", &a);
    if(a < 0) neg++;
    if(a > 0) pos++;
  }

  if(pos >= ceil(n/2.0)) puts("1");
  else if(neg >= ceil(n/2.0)) puts("-1");
  else puts("0");

  return 0;
}
