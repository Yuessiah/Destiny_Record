class Solution {
  public:
    int subarraySum(vector<int>& nums, int k) {
      int ans = 0;
      unordered_map<int, int> freq{{0, 1}};
      for (int i = 0, pre = 0; i < nums.size(); i++) {
        pre += nums[i];
        if (freq.count(pre-k)) ans += freq[pre-k];
        freq[pre]++;
      }

      return ans;
    }
};
