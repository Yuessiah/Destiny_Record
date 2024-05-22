class Solution {
public:
  int findKthLargest(vector<int>& nums, int k) {
    return Kth(nums, 0, nums.size(), k);
  }

  int Kth(vector<int>& nums, int i, int n, int k) {
    int g = i, ge = i; // greater, greater and equal
    for (int j = i; j < n-1; j++) {
      if (nums[j] < nums[n-1]) continue;
      if (nums[j] > nums[n-1]) {
        swap(nums[j], nums[g]);
        if (ge > g) swap(nums[j], nums[ge]);
        g++, ge++;
      } else swap(nums[j], nums[ge++]);
    }
    swap(nums[n-1], nums[ge++]);

    if (g-i >= k) return Kth(nums, i, g, k);
    else if (ge-i >= k) return nums[ge-1];
    return Kth(nums, ge, n, k-(ge-i));
  }
};
