#include<bits/stdc++.h>
using namespace std;

int n, k, cnt[26];

int main()
{
  scanf("%d%d", &n, &k);

  char c;
  for(int i = 0; i < n; i++) {
    scanf(" %c", &c);
    cnt[c-'A']++;
  }

  int ans = 0x7fffffff;
  for(int i = 0; i < k; i++) ans = min(ans, cnt[i]);

  printf("%d\n", ans*k);

  return 0;
}
