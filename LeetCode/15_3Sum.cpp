class Solution {
  public:
    vector<vector<int>> threeSum(vector<int>& nums) {
      sort(nums.begin(), nums.end());

      vector<int> tnums; // each element appears at most twice.
      for(int i = 0; i < nums.size(); i++) {
        if(i >= 2 && !nums[i-2] && !nums[i-1] && !nums[i]) ans.insert({0, 0, 0});
        if(i >= 2 && nums[i] == nums[i-2]) continue;
        tnums.push_back(nums[i]);
      }
      nums = tnums;

      for(int i = 0; i < nums.size(); i++)
        for(int j = i+1; j < nums.size(); j++) {
          int k = lower_bound(nums.begin(), nums.end(), -(nums[i]+nums[j])) - nums.begin();
          if(k == nums.size() || k == i || k == j || nums[i]+nums[j]+nums[k]) continue;
          ans.insert({nums[i], nums[j], nums[k]});
        }

      vector<vector<int>> rans;
      for(multiset<int> tri: ans) {
        auto it = tri.begin();
        rans.push_back({*it, *next(it), *next(next(it))});
      }

      return rans;
    }

  private:
    set<multiset<int>> ans;
};
