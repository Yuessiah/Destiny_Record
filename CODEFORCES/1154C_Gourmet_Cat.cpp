#include<bits/stdc++.h>
using namespace std;

int a, b, c;

int main()
{
  scanf("%d%d%d", &a, &b, &c);

  int ra = a/3, rb = b/2, rc = c/2, r;
  if(ra <= rb && ra <= rc) r = a/3;
  if(rc <= rb && rc <= ra) r = c/2;
  if(rb <= ra && rb <= rc) r = b/2;

  a = a-r*3;
  b = b-r*2;
  c = c-r*2;

  int ans = r*3 + r*2 + r*2, mx = 0;
  for(int i = 1; i <= 7; i++) {
    int *p, d = i, cnt = 0;
    int ta = a, tb = b, tc = c;

    while(1) {
      if(d == 1 || d == 4 || d == 7) p = &ta;
      else if(d == 2 || d == 6) p = &tb;
      else p = &tc;

      if(*p == 0) break;

      (*p)--;
      d = d%7 + 1;
      cnt++;
    }

    mx = max(mx, cnt);
  }

  printf("%d\n", ans + mx);

  return 0;
}
