#include<bits/stdc++.h>
using namespace std;

int const maxn = 2e5 + 10;

int n, a[maxn];
map<int, int> cnt;

int main()
{
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", &a[i]);

    for(int k = 0; k <= 5; k++) cnt[a[i]+k]++;
  }

  int best = 1;
  for(int i = 0; i < n; i++) best = max(best, cnt[a[i]]);

  printf("%d\n", best);

  return 0;
}
