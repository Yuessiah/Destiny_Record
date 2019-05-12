#include<bits/stdc++.h>
using namespace std;

int n, a;

int main()
{
  scanf("%d", &n);

  int ans = 1e9;
  for(int i = 0; i < n; i++) {
    scanf("%d", &a);
    ans = min(ans, a/max(i, n-1-i));
  }

  printf("%d\n", ans);

  return 0;
}
