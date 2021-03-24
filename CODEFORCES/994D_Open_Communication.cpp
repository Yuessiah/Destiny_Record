#include<bits/stdc++.h>
using namespace std;

int n, m;

int match(int f1, int s1, int f2, int s2) {
  if(f1 == f2 && s1 == s2 || f1 == s2 && s1 == f2) return 0;
  if(f1 == f2 || f1 == s2) return f1;
  if(s1 == f2 || s1 == s2) return s1;
  return 0;
}

int main()
{
  cin >> n >> m;

  vector<pair<int, int>> p1(n), p2(m);
  for(auto& [f, s]: p1) cin >> f >> s;
  for(auto& [f, s]: p2) cin >> f >> s;

  int ans = 0;
  bool zero = false, neg_one = false;
  for(int i = 0; i < 2; i++) {
    for(auto [f1, s1]: p1) {
      int know = 0;
      for(auto [f2, s2]: p2) {
        int cur = match(f1, s1, f2, s2);
        if(!know) know = cur;
        else if(cur && know != cur) neg_one = true;
      }

      if(!ans) ans = know;
      else if(know && ans != know) zero = true;
    }

    swap(p1, p2);
  }

  if(neg_one) puts("-1");
  else if(zero) puts("0");
  else cout << ans << endl;

  return 0;
}
