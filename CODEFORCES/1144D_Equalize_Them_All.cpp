#include<bits/stdc++.h>
using namespace std;

int const maxn = 2e5 + 10;

int n, a[maxn];

int main()
{
  scanf("%d", &n);

  int cnt[maxn], cmx = 0, cmx_a;
  vector<int> id;

  memset(cnt, 0, sizeof cnt);
  for(int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    cnt[a[i]]++;
  }

  for(int i = 1; i <= n; i++)
    if(cnt[a[i]] > cmx) {
      cmx = cnt[a[i]];
      cmx_a = a[i];
    }

  for(int i = 1; i <= n; i++)
    if(a[i] == cmx_a) id.push_back(i);

  printf("%d\n", n - cmx);


  int L = 1;
  for(auto &i: id) {
    for(int j = i-1; j >= L; j--)
      printf("%d %d %d\n", (a[j]>a[i]) + 1, j, j+1);
    L = i + 1;
  }

  for(int j = L; j <= n; j++)
    printf("%d %d %d\n", (a[j]>a[L-1]) + 1, j, j-1);

  return 0;
}
