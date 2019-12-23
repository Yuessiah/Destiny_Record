#include<bits/stdc++.h>
using namespace std;

int const maxn = 2e5 + 10;

int n, a[maxn];

int main()
{
  scanf("%d", &n);

  for(int i = 0; i < n; i++) scanf("%d", &a[i]);

  vector<bool> vis(n, false);
  vector<int> ans(n), come[n];
  queue<int> q;

  for(int i = 0; i < n; i++) {
    if(i+a[i] < n) {
      if(a[i]%2 != a[i+a[i]]%2) ans[i] = vis[i] = 1, q.push(i);
      come[i+a[i]].push_back(i);
    }
    if(i-a[i] >= 0) {
      if(a[i]%2 != a[i-a[i]]%2) ans[i] = vis[i] = 1, q.push(i);
      come[i-a[i]].push_back(i);
    }
  }

  while(q.size()) {
    int u = q.front(); q.pop();
    for(int v: come[u]) {
      if(!vis[v]) {
        vis[v] = true;
        ans[v] = ans[u] + 1;
        q.push(v);
      }
    }
  }

  for(int i = 0; i < n; i++) printf("%d ", vis[i]? ans[i] : -1);
  putchar('\n');

  return 0;
}
