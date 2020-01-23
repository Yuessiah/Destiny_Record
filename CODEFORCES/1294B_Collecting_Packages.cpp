#include<bits/stdc++.h>
using namespace std;

int t, n;

int main()
{
  scanf("%d", &t);
  while(t--) {
    scanf("%d", &n);

    vector<pair<int, int>> p(n+1);
    for(int i = 0; i < n; i++) scanf("%d%d", &p[i].second, &p[i].first);
    p[n] = {0, 0};

    sort(p.begin(), p.end());

    bool ok = true;
    string path;
    for(int i = 0; i+1 <= n; i++) {
      if(p[i].first > p[i+1].first || p[i].second > p[i+1].second) {
        ok = false;
        break;
      }

      int Uc = p[i+1].first - p[i].first;
      int Rc = p[i+1].second - p[i].second;
      path += string(Rc, 'R');
      path += string(Uc, 'U');
    }

    if(ok) cout << "YES\n" << path << '\n';
    else puts("NO");
  }

  return 0;
}
