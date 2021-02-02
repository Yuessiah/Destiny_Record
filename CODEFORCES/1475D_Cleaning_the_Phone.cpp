#include<bits/stdc++.h>
using namespace std;
typedef long long Int;

int constexpr maxn = 2e5 + 10;

int t, n, m, b;
Int a[maxn];

int main()
{
  cin >> t;
  while(t--) {
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<int> im[3]; // im := important
    for(int i = 0; i < n; i++)
      cin >> b, im[b].push_back(a[i]);

    sort(im[1].rbegin(), im[1].rend());
    sort(im[2].begin(), im[2].end());

    Int cost = 0, cln = 0; // cln := cleaned
    for(int v: im[2]) cost += 2, cln += v;

    Int ans = 3*n, n1 = im[1].size(), n2 = im[2].size(); // 3*n := INF
    for(int i = 0, j = 0; i <= n1; i++) {
      for(; j < n2 && cln-im[2][j] >= m; j++)
        cost -= 2, cln -= im[2][j];

      if(cln >= m) ans = min(ans, cost);

      if(i != n1)
        cost += 1, cln += im[1][i];
    }

    cout << (ans!=3*n? ans : -1) << endl;
  }

  return 0;
}
