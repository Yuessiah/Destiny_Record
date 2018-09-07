#include<bits/stdc++.h>
using namespace std;

int n;

int main()
{
  scanf("%d", &n);

  if(n == 1 || n == 2) puts("No");
  else {
    puts("Yes");
    printf("1 %d\n", n);

    printf("%d", n-1);
    for(int i = 1; i < n; i++) printf(" %d", i);
    putchar('\n');
  }

  return 0;
}
