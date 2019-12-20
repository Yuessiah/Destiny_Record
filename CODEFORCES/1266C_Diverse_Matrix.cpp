#include<bits/stdc++.h>
using namespace std;

int r, c;

int main()
{
  scanf("%d%d", &r, &c);

  if(r == 1 && c == 1) {
    puts("0");
    return 0;
  }

  for(int i = 1; i <= r; i++) {
    for(int j = 1; j <= c; j++) printf("%d ", c==1? i+1 : (r+j)*i);
    putchar('\n');
  }

  return 0;
}
