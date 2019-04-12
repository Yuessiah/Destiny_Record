#include<bits/stdc++.h>
using namespace std;

int const maxn = 510;

int n, m, A[maxn][maxn], B[maxn][maxn];

int main()
{
  scanf("%d%d", &n, &m);
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++) scanf("%d", &A[i][j]);

  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++) scanf("%d", &B[i][j]);

  for(int i = 0; i < n-1; i++)
    for(int j = 0; j < m-1; j++)
      if(A[i][j] != B[i][j]) {
        A[i][j]     ^= 1;
        A[i+1][j+1] ^= 1;
        A[i][j+1]   ^= 1;
        A[i+1][j]   ^= 1;
      }

  bool ok = true;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++) if(B[i][j] != A[i][j]) ok = false;

  puts(ok? "Yes" : "No");

  return 0;
}
