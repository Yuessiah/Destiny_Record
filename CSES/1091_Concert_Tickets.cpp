#include<bits/stdc++.h>
using namespace std;

int n, m, h, t;

int main()
{
  cin >> n >> m;

  multiset<int> S;
  for(int i = 0; i < n; i++) cin >> h, S.insert(h);

  for(int i = 0; i < m; i++) {
    cin >> t;

    auto it = S.upper_bound(t);
    if(it == S.begin()) cout << "-1\n";
    else {
      cout << *prev(it) << endl;
      S.erase(prev(it));
    }
  }

  return 0;
}
