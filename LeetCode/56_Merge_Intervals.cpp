class Solution {
  public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
      vector<pair<int, int>> line;
      for (vector<int> interval: intervals) {
        line.push_back({interval[0], +1});
        line.push_back({interval[1], -1});
      }

      int sum = 0, left, right;
      sort(line.begin(), line.end(), [](pair<int, int> a, pair<int, int> b) {
          if (a.first == b.first) return a.second > b.second;
          return a.first <= b.first;
          });
      for (pair<int, int> x: line) {
        if (!sum && x.second == +1) left = x.first;

        sum += x.second;

        if (!sum && x.second == -1) {
          vector<int> tmp{left, right = x.first};
          ans.emplace_back(tmp);
        }
      }

      return ans;
    }

  private:
    vector<vector<int>> ans;
};
