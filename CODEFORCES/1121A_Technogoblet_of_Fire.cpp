#include<bits/stdc++.h>
using namespace std;

int const maxn = 110;

int n, m, k, p[maxn], Ad[maxn], s[maxn], c;

int main()
{
  scanf("%d%d%d", &n, &m, &k);
  for(int i = 1; i <= n; i++) scanf("%d", &p[i]);

  memset(Ad, 0, sizeof Ad);

  for(int i = 1; i <= n; i++) {
    scanf("%d", &s[i]);

    if(Ad[s[i]] == 0) Ad[s[i]] = i;
    else if(p[Ad[s[i]]] < p[i]) Ad[s[i]] = i;
  }

  int cnt = 0;
  for(int i = 0; i < k; i++) {
    scanf("%d", &c);
    if(p[c] < p[Ad[s[c]]]) cnt++;
  }

  printf("%d\n", cnt);

  return 0;
}
