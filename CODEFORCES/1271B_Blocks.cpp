#include<bits/stdc++.h>
using namespace std;

int n;
string s;

int main()
{
  cin >> n >> s;

  for(char c: {'B', 'W'}) {
    string t = s;
    vector<int> ans;
    for(int i = 0; i+1 < n; i++) {
      if(t[i] == c) continue;
      t[i] = c, t[i+1] = (t[i+1]=='B')? 'W' : 'B';
      ans.push_back(i);
    }

    if(t.back() == c) {
      cout << ans.size() << endl;
      for(int i: ans) cout << i+1 << ' ';
      putchar('\n');
      return 0;
    }
  }

  puts("-1");

  return 0;
}
