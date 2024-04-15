class Solution {
  public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
      set<multiset<int>> dp[50];
      dp[0].insert(multiset<int>());

      for(int c: candidates)
        for(int t = c; t <= target; t++) {
          if(dp[t-c].empty()) continue;

          for(auto s: dp[t-c]) {
            s.insert(c);
            dp[t].insert(s);
          }
        }

      for(auto s: dp[target])
        ans.push_back(vector<int>(s.begin(), s.end()));

      return ans;
    }

  private:
    vector<vector<int>> ans;
};
