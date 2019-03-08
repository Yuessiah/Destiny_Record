#include<bits/stdc++.h>
using namespace std;

int const maxn = 2e5 + 10;

map<pair<int, int>, int> d;
int n, a[maxn], b[maxn];

int main()
{
  scanf("%d", &n);
  for(int i = 0; i < n; i++) scanf("%d", &a[i]);
  for(int i = 0; i < n; i++) scanf("%d", &b[i]);

  int add = 0; // additional
  for(int i = 0; i < n; i++) {
    if(!a[i]) {
      if(!b[i]) add++;
    } else {
      int g = __gcd(b[i], a[i]);
      d[make_pair(b[i]/g, a[i]/g)]++;
    }
  }

  int best = 0;
  for(auto it : d) best = max(best, it.second);

  printf("%d\n", best + add);

  return 0;
}
