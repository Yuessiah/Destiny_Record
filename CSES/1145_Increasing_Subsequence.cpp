#include<bits/stdc++.h>
using namespace std;

int const maxn = 2e5 + 10;

int n, x[maxn];

int main()
{
  cin >> n;
  for(int i = 0; i < n; i++) cin >> x[i];

  vector<int> s;
  for(int i = 0; i < n; i++) {
    auto p = lower_bound(s.begin(), s.end(), x[i]);
    if(p == s.end()) s.push_back(x[i]);
    else *p = x[i];
  }

  cout << s.size() << endl;

  return 0;
}
