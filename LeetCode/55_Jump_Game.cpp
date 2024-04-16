class Solution {
  public:
    bool canJump(vector<int>& nums) {
      for (int i = 0, bound = 0; i < nums.size(); i++) {
        if (i > bound) return false;
        bound = max(bound, i + nums[i]);
      }

      return true;
    }
};
