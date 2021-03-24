#include<bits/stdc++.h>
using namespace std;
typedef long long Int;

int constexpr maxn = 4010;

Int n, v[maxn], d[maxn], p[maxn];

int main()
{
  cin >> n;
  for(int i = 0; i < n; i++) cin >> v[i] >> d[i] >> p[i];

  vector<int> ans;
  for(int i = 0; i < n; i++) {
    if(p[i] < 0) continue;
    ans.push_back(i);

    for(Int j = i+1, s = 0; (v[i] || s) && j < n; j++) {
      if(p[j] < 0) continue;

      p[j] -= v[i] + s;
      if(p[j] < 0) s += d[j];
      if(v[i] > 0) v[i]--;
    }
  }

  cout << ans.size() << endl;
  for(int i: ans) cout << i+1 << ' ';
  cout << endl;

  return 0;
}
