#include<bits/stdc++.h>
using namespace std;

int q;
string s;

int main()
{
  scanf("%d", &q);
  while(q--) {
    cin >> s;

    int L = 0, R = 0, U = 0, D = 0;
    for(char c: s) {
      if(c == 'L') L++;
      if(c == 'R') R++;
      if(c == 'U') U++;
      if(c == 'D') D++;
    }

    int x = min(L, R);
    int y = min(U, D);

    if(y == 0 && x) printf("2\nLR");
    else if(x == 0 && y) printf("2\nUD");
    else {
      printf("%d\n", x+y+x+y);
      for(int i = 0; i < x; i++) putchar('L');
      for(int i = 0; i < y; i++) putchar('U');
      for(int i = 0; i < x; i++) putchar('R');
      for(int i = 0; i < y; i++) putchar('D');
    }
    putchar('\n');
  }
  return 0;
}
