#include<cstdio>
#include<vector>
#include<set>
using namespace std;

int m, n;
vector<pair<int, int> > want;
set<pair<int, int> > real;

int main()
{
  while(scanf("%d", &m) && m) {
    //init
    want.clear();
    real.clear();

    int x, y;
    for(int i = 0; i < m; i++) {
      scanf("%d%d", &x, &y);
      want.emplace_back(x, y);
    }

    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
      scanf("%d%d", &x, &y);
      real.emplace(x, y);
    }

    for(auto star: real) {
      int dx = star.first  - want[0].first;
      int dy = star.second - want[0].second;

      int i;
      for(i = 0; i < m; i++) {
        if(real.find(make_pair(want[i].first + dx, want[i].second + dy)) == real.end()) break;
      }

      if(i == m) printf("%d %d\n", dx, dy);
    }
  }

  return 0;
}
