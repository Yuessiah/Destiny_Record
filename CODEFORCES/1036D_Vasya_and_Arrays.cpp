#include<cstdio>

int const maxn = 3*1e5 + 10;

int n, m, a[maxn], b[maxn];

int main()
{
  scanf("%d", &n);
  for(int i = 0; i < n; i++) scanf("%d", &a[i]);
  scanf("%d", &m);
  for(int i = 0; i < m; i++) scanf("%d", &b[i]);

  int ans = 0, x = 0, y = 0;
  long long int A = a[x++], B = b[y++];

  while(x != n || y != m) {
    if(A == B) {
      if(x == n || y == m) break;
      A = a[x++]; B = b[y++];
      ans++;
    }

    while(y != m && (x == n || A > B)) B += b[y++];
    while(x != n && (y == m || A < B)) A += a[x++];
  }

  if(x == n && y == m && A == B) printf("%d\n", ans+1);
  else puts("-1");

  return 0;
}
