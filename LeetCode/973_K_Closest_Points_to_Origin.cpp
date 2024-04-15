class Solution {
  public:
    int dist(int x, int y) {
      return x*x + y*y;
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
      priority_queue<pair<int, int>> q; // max heap

      for(int i = 0; i < points.size(); i++) {
        q.emplace(dist(points[i][0], points[i][1]), i);
        if(q.size() > k) q.pop(); // pop the max
      }

      while(q.size()) {
        auto [d, i] = q.top(); q.pop();
        ans.push_back(points[i]);
      }
      return ans;
    }

  private:
    vector<vector<int>> ans;
};
