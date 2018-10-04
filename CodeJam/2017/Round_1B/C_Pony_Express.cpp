#include<cstdio>
#include<cstring>
#include<algorithm>
using std::min;

const long long int maxn = 100 + 10;
const long long int INF = maxn*1000000000;

long long int dist[maxn][maxn];
double time[maxn][maxn];

struct horse {
  int E, S;
}h[maxn];

int main()
{
  int T, kase=0;
  scanf("%d", &T);

  while(T--) {
    int N, Q;
    scanf("%d%d", &N, &Q);
    for(int i = 1; i <= N; i++) scanf("%d%d", &h[i].E, &h[i].S);

    for(int u = 1; u <= N; u++)
      for(int v = 1; v <= N; v++) {
        int D;
        scanf("%d", &D);
        if(D == -1) dist[u][v] = INF;
        else dist[u][v] = D;
        if(u == v) dist[u][v] = 0;
      }

    for(int k = 1; k <= N; k++)
      for(int u = 1; u <= N; u++)
        for(int v = 1; v <= N; v++)
          dist[u][v] = min(dist[u][v], dist[u][k] + dist[k][v]);

    for(int u = 1; u <= N; u++)
      for(int v = 1; v <= N; v++) if(u != v) {
        double W;
        if(h[u].E >= dist[u][v]) W = (double)dist[u][v]/h[u].S;
        else W = (double)INF;
        time[u][v] = W;
      } else time[u][v] = 0;

    for(int k = 1; k <= N; k++)
      for(int u = 1; u <= N; u++)
        for(int v = 1; v <= N; v++)
          time[u][v] = min(time[u][v], time[u][k] + time[k][v]);

    printf("Case #%d: ", ++kase);
    while(Q--) {
      int U, V;
      scanf("%d%d", &U, &V);
      printf("%lf", time[U][V]);
      if(Q) putchar(' ');
    } putchar('\n');
  }

  return 0;
}
