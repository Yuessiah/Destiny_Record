#include<bits/stdc++.h>
using namespace std;

int n, q;

int main()
{
  cin >> n >> q;

  vector<pair<int, int>> p(q);
  for(auto& [l, r]: p) cin >> l >> r;

  vector<vector<int>> p_at(n+1);
  for(int i = 0; i < q; i++) {
    auto [l, r] = p[i];
    for(int x = l; x <= r; x++) p_at[x].push_back(i);
  }

  int sum = 0;
  vector<int> one(q, 0);
  vector<vector<int>> two(q, vector<int>(q, 0));
  for(int x = 1; x <= n; x++) {
    sum += !p_at[x].empty();
    if(p_at[x].size() == 1) one[p_at[x][0]]++;
    if(p_at[x].size() == 2) two[p_at[x][0]][p_at[x][1]]++, two[p_at[x][1]][p_at[x][0]]++;
  }

  int best = 0;
  for(int i = 0; i < q; i++)
    for(int j = i+1; j < q; j++)
      best = max(best, sum - one[i] - one[j] - two[i][j]);

  cout << best << endl;

  return 0;
}
