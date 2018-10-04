#include<bits/stdc++.h>
using namespace std;

int const maxv = 55, INF = 1e5;

int V, E, d[maxv][maxv]; //d := distance

int main()
{
  int T, kase = 0;
  scanf("%d", &T);

  while(T--) {
    for(int i = 0; i < maxv; i++)
      for(int j = 0; j < maxv; j++) d[i][j] = INF;

    scanf("%d%d", &V, &E);

    int A, B, L;
    for(int i = 0; i < E; i++) {
      scanf("%d%d%d", &A, &B, &L);
      d[A][B] = d[B][A] = L;
    }

    for(int u = 1; u <= V; u++) d[u][u] = 0;

    for(int k = 1; k <= V; k++)
      for(int i = 1; i <= V; i++)
        for(int j = 1; j <= V; j++)
          d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

    map<int, int> mp;

    for(int i = 1; i < (1<<V)-1; i++) {
      int sum = 0;

      for(int x = 1; x <= V; x++) {
        int cur = INF; //cur := current

        for(int y = 1; y <= V; y++) if(d[x][y] != INF) {
          bool x_p = (1<<(x-1))&i, y_p = (1<<(y-1))&i;
          if(x_p != y_p) cur = min(cur, d[x][y]);
        }

        sum += cur;
      }

      if(mp.count(sum)) mp[sum]++;
      else mp[sum] = 1;
    }

    printf("Case #%d: %d\n", ++kase, mp.begin()->second);
  }

  return 0;
}
