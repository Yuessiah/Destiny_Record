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

    vector<char> a, b;
    for(int i = 0; i < n; i++) {
      if(s[i] == t[i]) continue;
      a.push_back(s[i]);
      b.push_back(t[i]);
    }

    if(a.size() != 2 || a[0] != a[1] || b[0] != b[1]) puts("No");
    else puts("Yes");
  }

  return 0;
}
