#include<bits/stdc++.h>
using namespace std;

int const maxn = 55;
int const pr[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47 };
int const p_size = sizeof(pr)/sizeof(int);

int N, a[maxn], cnt[maxn];
bool G[maxn][maxn], vis[maxn];

int dfs(int u) {
  vis[u] = true;

  int sum = 0;
  for(int v = 0; v < maxn; v++)
    if(G[u][v] && !vis[v]) sum += 1 + dfs(v);

  return sum;
}

int main()
{
  int T;
  scanf("%d", &T);

  while(T--) {
    memset(G, false, sizeof(G));
    memset(vis, false, sizeof(vis));
    memset(cnt, 0, sizeof(cnt));

    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
      scanf("%d", &a[i]);
      cnt[a[i]]++;
    }

    for(int i = 0; i < N; i++)
      for(int j = i+1; j < N; j++)
        if(__gcd(a[i], a[j]) == 1)
          G[i][j] = G[j][i] = 1;

    bool conn = true;
    if(dfs(0) != N-1) conn = false;

    if(conn) {
      puts("0");
      for(int i = 0; i < N; i++) printf("%d%c", a[i], (i<N-1)? ' ' : '\n');
      continue;
    }

    puts("1");
    for(int i = p_size-1; i >= 0; i--)
      if(cnt[pr[i]] == 0) {
        printf("%d ", pr[i]);
        break;
      }
    for(int i = 1; i < N; i++) printf("%d%c", a[i], (i<N-1)? ' ' : '\n');
  }

  return 0;
}
