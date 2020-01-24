#include<bits/stdc++.h>
using namespace std;

int const maxn = 1e5 + 10;

int n, q, r, c;

int main()
{
  scanf("%d%d", &n, &q);

  int lava[2][maxn] = {}, cnt = 0;
  while(q--) {
    scanf("%d%d", &r, &c), r--;

    lava[r][c] ^= 1;
    for(int d = c-1; d <= c+1; d++)
      if(lava[r^1][d]) cnt += lava[r][c]? 1 : -1;

    puts(cnt? "No" : "Yes");
  }

  return 0;
}
