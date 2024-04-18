class Solution {
  public:
    vector<vector<int>> subsets(vector<int>& nums) {
      vector<int> choice;
      dfs(0, choice, nums);
      return ans;
    }

    void dfs(int i, vector<int>& choice, vector<int>& nums) {
      if (i == nums.size()) {
        ans.push_back(choice);
        return;
      }

      dfs(i+1, choice, nums);

      choice.push_back(nums[i]);
      dfs(i+1, choice, nums);
      choice.pop_back();
    }

  private:
    vector<vector<int>> ans;
};
