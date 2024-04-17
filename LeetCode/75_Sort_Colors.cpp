class Solution {
  public:
    void sortColors(vector<int>& nums) {
      int j = 0;

      for (int i = j; i < nums.size(); i++)
        if (nums[i] == 0) swap(nums[i], nums[j++]);

      for (int i = j; i < nums.size(); i++)
        if (nums[i] == 1) swap(nums[i], nums[j++]);

      for (int i = j; i < nums.size(); i++)
        if (nums[i] == 2) swap(nums[i], nums[j++]);
    }
};
