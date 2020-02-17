#include<bits/stdc++.h>
using namespace std;

int n, m;
string s;

int main()
{
  scanf("%d%d", &n, &m);

  set<string> dic;
  string mid, ans;
  for(int i = 0; i < n; i++) {
    cin >> s;

    string r(s);
    reverse(r.begin(), r.end());

    if(s == r) { mid = s; continue; }
    if(dic.count(r)) ans += r;
    dic.insert(s);
  }

  string r(ans);
  reverse(r.begin(), r.end());
  ans += mid + r;

  cout << ans.length() << '\n' << ans << endl;

  return 0;
}
