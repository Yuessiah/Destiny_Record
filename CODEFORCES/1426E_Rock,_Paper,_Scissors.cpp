#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> a(4), b(4);

int main()
{
  scanf("%d", &n);
  scanf("%d%d%d", &a[0], &a[1], &a[2]);
  scanf("%d%d%d", &b[0], &b[1], &b[2]);

  int max_win = 0, min_win = n;

  vector<pair<int, int>> ord;
  ord.push_back({0, 2});
  ord.push_back({1, 0});
  ord.push_back({2, 1});
  ord.push_back({0, 0});
  ord.push_back({1, 1});
  ord.push_back({2, 2});

  sort(ord.begin(), ord.end());
  do {
    vector<int> _a(a), _b(b);
    for(auto [c1, c2]: ord) {
      int no_win = min(_a[c1], _b[c2]);
      _a[c1] -= no_win, _b[c2] -= no_win;
    }
    min_win = min(min_win, min(_a[0], _b[1]) + min(_a[1], _b[2]) + min(_a[2], _b[0]));
  } while(next_permutation(ord.begin(), ord.end()));

  max_win += min(a[0], b[1]) + min(a[1], b[2]) + min(a[2], b[0]);

  printf("%d %d\n", min_win, max_win);

  return 0;
}
