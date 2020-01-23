#include<bits/stdc++.h>
using namespace std;

int q, x, y;
map<int, int> cnt;

int main()
{
  scanf("%d%d", &q, &x);

  int MEX = 0;
  while(q--) {
    scanf("%d", &y);
    cnt[y%x]++;

    while(cnt[MEX%x]) cnt[MEX%x]--, MEX++;

    printf("%d\n", MEX);
  }

  return 0;
}
