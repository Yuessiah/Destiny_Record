#include<bits/stdc++.h>
using namespace std;

int const maxN = 1e5 + 10;

int N, ut, va;
vector<int> E[maxN];

int main()
{
  scanf("%d%d%d", &N, &ut, &va);
  for(int i = 0; i < N-1; i++) {
    int A, B;
    scanf("%d%d", &A, &B);
    E[A].push_back(B);
    E[B].push_back(A);
  }

  if(ut == va) { puts("0"); return 0; }


  int aoki[maxN];
  vector<bool> vis(N+1, false);
  queue<pair<int, int>> q;
  vis[va] = true;
  q.push({va, 0});

  while(q.size()) {
    int u, t;
    tie(u, t) = q.front(); q.pop();
    aoki[u] = t;
    for(int v: E[u])
      if(!vis[v]) q.push({v, t+1}), vis[v] = true;
  }

  int taka[maxN]; // takahashi
  memset(taka, -1, sizeof taka);
  vis.assign(N+1, false);
  vis[ut] = true;
  q.push({ut, 0});

  while(q.size()) {
    int u, t;
    tie(u, t) = q.front(); q.pop();
    taka[u] = t;
    for(int v: E[u])
      if(!vis[v] && t+1 <= aoki[v]) q.push({v, t+1}), vis[v] = true;
  }


  int ans = 0;
  for(int i = 1; i <= N; i++)
    if(taka[i] != -1) ans = max(ans, aoki[i]-1);

  printf("%d\n", ans);

  return 0;
}
