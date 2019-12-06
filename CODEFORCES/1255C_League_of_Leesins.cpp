#include<bits/stdc++.h>
using namespace std;

int const maxn = 1e5 + 10;

int n, x, y, z;

int main()
{
  scanf("%d", &n);

  int cnt[maxn] = {};
  map<pair<int, int>, vector<int>> tp; // tp := triple

  for(int i = 0; i < n-2; i++) {
    scanf("%d%d%d", &x, &y, &z);

    tp[{x, y}].push_back(z);
    tp[{y, x}].push_back(z);
    tp[{y, z}].push_back(x);
    tp[{z, y}].push_back(x);
    tp[{z, x}].push_back(y);
    tp[{x, z}].push_back(y);

    cnt[x]++;
    cnt[y]++;
    cnt[z]++;
  }

  int p1, p2;
  for(int i = 1; i <= n; i++) if(cnt[i] == 1) p1 = i;
  for(int i = 1; i <= n; i++) if(cnt[i] == 2 && tp.count({p1, i})) p2 = i;

  bool vis[maxn] = {};
  for(int i = 0; i < n; i++) {
    printf("%d ", p1);
    vis[p1] = true;

    if(i == n-1) break;

    auto v = tp[{p1, p2}];
    p1 = p2;
    p2 = vis[v[0]]? v[1] : v[0];
  }

  return 0;
}
