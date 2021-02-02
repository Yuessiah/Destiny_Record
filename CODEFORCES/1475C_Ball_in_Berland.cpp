#include<bits/stdc++.h>
using namespace std;

int t, a, b, k;
vector<pair<int, int>> p;

int main()
{
  cin >> t;
  while(t--) {
    cin >> a >> b >> k;

    p.resize(k);
    vector<int> cnta(a+1, 0), cntb(b+1, 0);
    for(auto& [a, b]: p) cin >> a, cnta[a]++;
    for(auto& [a, b]: p) cin >> b, cntb[b]++;

    long long ans = 0;
    for(auto& [a, b]: p) ans += k-1 -(cnta[a]-1) -(cntb[b]-1);
    cout << (ans /= 2) << endl;
  }

  return 0;
}
