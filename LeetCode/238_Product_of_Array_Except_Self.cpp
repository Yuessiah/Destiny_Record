class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& nums) {
      ans.resize(nums.size(), 1);
      for(int i = 1, prd = 1; i < nums.size(); i++) {
        prd *= nums[i-1];
        ans[i] *= prd;
      }

      for(int i = (nums.size()-1) - 1, prd = 1; i >= 0; i--) {
        prd *= nums[i+1];
        ans[i] *= prd;
      }

      return ans;
    }

  private:
    vector<int> ans;
};
