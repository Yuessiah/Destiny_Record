#include<bits/stdc++.h>
using namespace std;

int const maxn = 2e3 + 10;

int t, n;
char a[maxn][maxn];

int main()
{
  cin >> t;
  while(t--) {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];

    int ans[10] = {}, mx_r[10] = {}, mx_c[10] = {}, mi_r[10], mi_c[10];
    fill(mi_c, mi_c+10, n);
    fill(mi_r, mi_r+10, n);

    for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++) {
        int d = a[i][j] - '0';
        mx_r[d] = max(mx_r[d], i), mi_r[d] = min(mi_r[d], i);
        mx_c[d] = max(mx_c[d], j), mi_c[d] = min(mi_c[d], j);
      }

    for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++) {
        int d = a[i][j] - '0';
        ans[d] = max({ans[d],
            max(i, n-1-i) * max(j-mi_c[d], mx_c[d]-j),
            max(j, n-1-j) * max(i-mi_r[d], mx_r[d]-i)});
      }

    for(int d = 0; d <= 9; d++) cout << ans[d] << ' ';
    cout << endl;
  }

  return 0;
}
