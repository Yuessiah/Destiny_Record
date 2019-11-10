#include<bits/stdc++.h>
using namespace std;

int k, n;
string s, t;

int main()
{
  scanf("%d", &k);

  while(k--) {
    scanf("%d", &n);
    cin >> s >> t;

    vector<pair<int, int>> ans;
    for(int i = 0; i < n; i++) {
      if(s[i] == t[i]) continue;

      for(int j = i+1; j < n; j++) {
        if(s[j] == s[i]) {
          swap(s[j], t[i]);
          ans.emplace_back(j, i);
          break;
        } else if(t[j] == s[i]) {
          swap(s[i], t[i]);
          ans.emplace_back(i, i);
          swap(s[i], t[j]);
          ans.emplace_back(i, j);
          break;
        }
      }
    }

    if(s != t) puts("No");
    else {
      puts("Yes");
      printf("%d\n", (int)ans.size());
      for(auto it: ans) printf("%d %d\n", it.first+1, it.second+1);
    }
  }

  return 0;
}
