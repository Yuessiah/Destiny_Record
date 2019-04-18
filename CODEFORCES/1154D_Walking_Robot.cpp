#include<bits/stdc++.h>
using namespace std;

int const maxn = 2e5 + 10;

int n, b, a, s[maxn];

int main()
{
  scanf("%d%d%d", &n, &b, &a);
  for(int i = 1; i <= n; i++) scanf("%d", &s[i]);

  int cnt = 0, a_max = a;
  for(int i = 1; i <= n; i++) {
    if(a == a_max) a--;
    else if(s[i] == 1 && b > 0) b--, a++;
    else if(s[i] == 1 && b == 0 && a > 0) a--;
    else if(s[i] == 0 && a > 0) a--;
    else if(s[i] == 0 && b > 0) b--;
    else break;
    cnt++;
  }

  printf("%d\n", cnt);

  return 0;
}
