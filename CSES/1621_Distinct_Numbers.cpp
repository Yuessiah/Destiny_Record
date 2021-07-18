#include<bits/stdc++.h>
using namespace std;

int n, a;

int main()
{
  cin >> n;

  set<int> S;
  for(int i = 0; i < n; i++) cin >> a, S.insert(a);
  cout << S.size() << endl;

  return 0;
}
