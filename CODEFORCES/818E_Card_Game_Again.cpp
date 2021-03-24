#include<bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

int const maxn = 1e5 + 10;

int n, k, a[maxn];
vector<pair<int, int>> f;
vector<int> at[maxn];

bool chk(vector<int> pro) { // check
  int ok = true;
  for(int i = 0; i < f.size(); i++) {
    auto [t, _] = f[i];
    if(pro[i] < t) ok = false;
  }

  return ok;
}

int main()
{
  cin >> n >> k;

  for(int d = 2; d*d <= k; d++) {
    if(k%d) continue;
    int t = 0;
    while(k%d == 0) t++, k /= d;
    f.push_back({t, d});
  }
  if(k > 1) f.push_back({1, k});

  for(int i = 0; i < n; i++) {
    cin >> a[i];

    for(auto [_, d]: f) {
      int t = 0;
      while(a[i]%d == 0) t++, a[i] /= d;
      at[i].push_back(t);
    }
  }

  long long ans = 0;
  vector<int> pro(at[0]); // product
  for(int l = 0, r = 1; l < n; l++) {
    for(; r < n; r++) {
      if(r > l && chk(pro)) break;
      transform(all(pro), at[r].begin(), pro.begin(), plus<int>());
    }

    if(chk(pro)) ans += n - r + 1;
    transform(all(pro), at[l].begin(), pro.begin(), minus<int>());
  }

  cout << ans << endl;

  return 0;
}
