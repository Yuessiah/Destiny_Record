class Solution {
  public:
    int orangesRotting(vector<vector<int>>& grid) {
      queue<pair<pair<int, int>, int>> q;
      for(int i = 0; i < grid.size(); i++)
        for(int j = 0; j < grid[0].size(); j++)
          if(grid[i][j] == 2) q.push({{i, j}, 0});

      int ans = 0;
      vector<vector<bool>> vis(grid.size(), vector<bool>(grid[0].size(), false));
      while(q.size()) {
        auto [u, d] = q.front(); q.pop();
        auto [x, y] = u;

        vector<pair<int, int>> nxt = {{x, y+1}, {x+1, y}, {x-1, y}, {x, y-1}};
        for(auto [nx, ny]: nxt) {
          if(nx < 0 || ny < 0 || nx >= grid.size() || ny >= grid[0].size()) continue;
          if(vis[nx][ny] || grid[nx][ny] != 1) continue;
          vis[nx][ny] = true;
          grid[nx][ny] = 2;
          q.push({{nx, ny}, ans=d+1});
        }
      }

      for(int i = 0; i < grid.size(); i++)
        for(int j = 0; j < grid[0].size(); j++)
          if(grid[i][j] == 1) return -1;
      return ans;
    }
};
