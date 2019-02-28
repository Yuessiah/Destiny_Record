#include<bits/stdc++.h>
using namespace std;

int const maxs = 2e5 + 10;

int n, k, x = 0, c[26];
char s[maxs];

int main()
{

  scanf("%d%d", &n, &k);
  scanf("%s", &s);

  int cnt = 1;
  for(int i = 1; s[i-1] != '\0'; i++) {
    if(s[i] == s[i-1]) cnt++;
    else {
      c[s[i-1]] += cnt/k;
      cnt = 1;

      x = max(x, c[s[i-1]]);
    }
  }

  printf("%d\n", x);

  return 0;
}
