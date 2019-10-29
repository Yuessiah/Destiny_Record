#include<bits/stdc++.h>
using namespace std;

int t;
string s;

template<class itr>
auto cut(itr s, itr t) {
  vector<pair<char, int>> res;
  for(auto it = s; it != t; it++) {
    if(res.empty() || res.back().first != *it) res.emplace_back(*it, 1);
    else res.back().second++;
  }

  return res;
}

int main()
{
  scanf("%d", &t);

  while(t--) {
    cin >> s;

    set<char> ans;
    for(auto it: cut(s.begin(), s.end()))
      if(it.second&1) ans.insert(it.first);

    for(auto it: ans) printf("%c", it);
    putchar('\n');
  }

  return 0;
}
