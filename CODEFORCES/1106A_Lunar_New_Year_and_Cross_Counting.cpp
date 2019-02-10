#include<bits/stdc++.h>
using namespace std;

int const maxn = 510;

int n, M[maxn][maxn];

int main()
{
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++) scanf(" %c", &M[i][j]);

  int cnt = 0;
  for(int i = 1; i < n-1; i++)
    for(int j = 1; j < n-1; j++)
      if(M[i][j] == 'X' &&
          M[i][j] == M[i-1][j-1] &&
          M[i-1][j-1] == M[i-1][j+1] &&
          M[i-1][j+1] == M[i+1][j-1] &&
          M[i+1][j-1] == M[i+1][j+1]) cnt++;

  printf("%d\n", cnt);

  return 0;
}
