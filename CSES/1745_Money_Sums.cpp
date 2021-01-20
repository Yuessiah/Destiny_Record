#include<bits/stdc++.h>
using namespace std;

int const maxn = 110;

int n, x[maxn];

int main()
{
  cin >> n;
  for(int i = 0; i < n; i++) cin >> x[i];

  set<int> S;
  for(int i = 0; i < n; i++) {
    set<int> T(S);
    for(int e: T) S.insert(e + x[i]);
    S.insert(x[i]);
  }

  cout << S.size() << endl;
  for(int e: S) cout << e << ' ';
  cout << endl;

  return 0;
}
