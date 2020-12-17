#include<bits/stdc++.h>
using namespace std;

int t, n;

int main()
{
  scanf("%d", &t);

  while(t--) {
    scanf("%d", &n);
    if(n == 1) { puts("0"); continue; }
    printf("%d\n", (int)sqrt(n)-1 + (int)ceil((double)n/(int)sqrt(n))-1);
  }

  return 0;
}
