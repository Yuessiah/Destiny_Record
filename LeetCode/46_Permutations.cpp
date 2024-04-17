class Solution {
  public:
    vector<vector<int>> permute(vector<int>& nums) {
      set<int> S(nums.begin(), nums.end());
      vector<int> gen;
      dfs(gen, S);
      return ans;
    }

    void dfs(vector<int>& gen, set<int>& S) {
      if (S.empty()) {
        ans.push_back(gen);
        return;
      }

      set<int> T(S);
      for (int x: S) {
        T.erase(x);
        gen.push_back(x);
        dfs(gen, T);
        gen.pop_back();
        T.insert(x);
      }
    }

  private:
    vector<vector<int>> ans;
};
