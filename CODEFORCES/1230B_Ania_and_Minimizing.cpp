#include<bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;

int n, k;
char S[maxn];

int main()
{
  scanf("%d%d", &n, &k);
  scanf("%s", S);

  if(k == 0) {
    printf("%s\n", S);
    return 0;
  }

  if(n == 1) {
    puts("0");
    return 0;
  }

  if(S[0] != '1') { k--; S[0] = '1'; }
  for(int i = 1; i < n && k; i++)
    if(S[i] != '0') { k--; S[i] = '0'; }

  printf("%s\n", S);

  return 0;
}
