#include<bits/stdc++.h>
using namespace std;

int const maxk = 111;

int n, k, d, p[maxk];

int main()
{
  scanf("%d%d", &n, &k);
  for(int i = 0; i < n; i++) scanf("%d", &d), p[d%k]++;

  int cnt = p[0]/2;
  for(int i = 1; i <= k/2; i++) {
    if(!(k&1) && i == k/2) {
      cnt += p[i]/2;
    } else cnt += min(p[i], p[k-i]);
  }

  printf("%d\n", 2*cnt);

  return 0;
}
