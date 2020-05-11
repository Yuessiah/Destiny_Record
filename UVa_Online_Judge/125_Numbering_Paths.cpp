#include<bits/stdc++.h>
using namespace std;

int const maxm = 35;

int n, j, k, m, M[maxm][maxm];

int main()
{
  int kase = 0;

  while(~scanf("%d", &n)) {
    m = 0;
    memset(M, 0, sizeof M);
    while(n--) {
      scanf("%d%d", &j, &k);
      M[j][k]++;

      m = max({m, j, k});
    }

    for(int i = 0; i <= m; i++)
      for(j = 0; j <= m; j++)
        for(k = 0; k <= m; k++)
          M[j][k] += M[j][i] * M[i][k];

    for(int i = 0; i <= m; i++) {
      if(!M[i][i]) continue;
      for(j = 0; j <= m; j++)
        for(k = 0; k <= m; k++)
          if(M[j][i] && M[i][k]) M[j][k] = -1;
    }

    printf("matrix for city %d\n", kase++);
    for(j = 0; j <= m; j++)
      for(k = 0; k <= m; k++)
        printf("%d%c", M[j][k], " \n"[k==m]);
  }

  return 0;
}
