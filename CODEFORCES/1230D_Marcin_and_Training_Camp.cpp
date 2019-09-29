#include<bits/stdc++.h>
using namespace std;

typedef long long Int;
int const maxn = 7010;

int n, b[maxn];
Int a[maxn];
map<Int, int> cnt;

int main()
{
  scanf("%d", &n);
  for(int i = 0; i < n; i++) scanf("%lld", &a[i]), cnt[a[i]]++;
  for(int i = 0; i < n; i++) scanf("%d", &b[i]);

  vector<Int> group; // allowed "a" value in group
  for(auto it: cnt) if(it.second >= 2) group.push_back(it.first);

  Int sum = 0;
  for(int i = 0; i < n; i++)
    for(Int _a: group) if((_a&a[i]) == a[i]) {
      sum += b[i];
      break;
    }

  printf("%lld\n", sum);

  return 0;
}
