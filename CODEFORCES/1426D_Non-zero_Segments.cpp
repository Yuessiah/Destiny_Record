#include<bits/stdc++.h>
using namespace std;
typedef long long Int;

int const maxn = 2e5 + 10;

int n;
Int a[maxn];

int main()
{
  scanf("%d", &n);
  for(int i = 0; i < n; i++) scanf("%lld", &a[i]);

  set<Int> S;
  S.insert(0);

  Int sum = 0;
  int ans = 0;
  for(int i = 0; i < n; i++) {
    sum += a[i];

    if(S.count(sum)) {
      ans++;
      S.clear();
      S.insert(0);
      S.insert(sum = a[i]);
    } else S.insert(sum);
  }

  printf("%d\n", ans);

  return 0;
}
