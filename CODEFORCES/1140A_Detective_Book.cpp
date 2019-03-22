#include<bits/stdc++.h>
using namespace std;

int const maxn = 1e4 + 10;

int n, a;

int main()
{
  scanf("%d", &n);

  int day = 0, page = 1;
  for(int i = 1; i <= n; i++) {
    scanf("%d", &a);
    page = max(page, a);
    if(page == i) day++;
  }

  printf("%d\n", day);

  return 0;
}
