#include<bits/stdc++.h>
using namespace std;

int const maxn = 2e5 + 10;

int n, a[maxn];
multiset<int> b;

int main()
{
  scanf("%d", &n);
  for(int i = 0; i < n; i++) scanf("%d", &a[i]);
  for(int i = 0, t; i < n; i++) scanf("%d", &t), b.insert(t);

  for(int i = 0; i < n; i++) {
    auto it = b.lower_bound((n - a[i]) % n);
    if(it == b.end()) it = b.begin();

    printf("%d ", (*it + a[i]) % n);
    b.erase(it);
  }
  putchar('\n');

  return 0;
}
