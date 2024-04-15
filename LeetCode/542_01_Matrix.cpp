class Solution {
  public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
      ans = mat; // set same sizes
      for(auto &x: ans) for(int &y: x) y = 0;

      queue<pair<pair<int, int>, int>> q;
      for(int i = 0; i < mat.size(); i++)
        for(int j = 0; j < mat[0].size(); j++) {
          if(mat[i][j] != 0) continue;
          q.push({{i, j}, 0});
        }

      vector<vector<int>> vis = ans; // all zero(false)
      while(q.size()) {
        auto [u, d] = q.front(); q.pop();
        auto [x, y] = u;

        if(mat[x][y] != 0) ans[x][y] = d;

        vector<pair<int, int>> dir{{x, y+1}, {x+1, y}, {x-1, y}, {x, y-1}};
        for(auto [dx, dy]: dir) {
          if(0 > dx || dx >= mat.size() || 0 > dy || dy >= mat[0].size()) continue;
          if(vis[dx][dy] || mat[dx][dy] == 0) continue;

          vis[dx][dy] = true;
          q.push({{dx, dy}, d+1});
        }
      }

      return ans;
    }

  private:
    vector<vector<int>> ans;
};
