#include<bits/stdc++.h>
using namespace std;

int n, a;

int main()
{
  scanf("%d", &n);

  int t = 1;
  for(int i = 0; i < n; i++) {
    scanf("%d", &a);
    printf("%d\n", (a&1)? (a+(t*=-1))/2 : a/2);
  }

  return 0;
}
