class Solution {
  public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
      int t = nums1.size() + nums2.size();
      if (t%2) return findKth(nums1, 0, nums2, 0, 1+t/2);
      else return (findKth(nums1, 0, nums2, 0, t/2) + findKth(nums1, 0, nums2, 0, 1+t/2))/2.0;
    }

    int findKth(vector<int>& nums1, int i, vector<int>& nums2, int j, int k) {
      int n = nums1.size(), m = nums2.size();
      if (n-i < m-j) return findKth(nums2, j, nums1, i, k);
      if (j == m) return nums1[i+k-1];
      if (k == 1) return min(nums1[i], nums2[j]);

      int k2 = min(m-j, k/2);
      int k1 = k - k2;

      if (nums1[i+k1-1] > nums2[j+k2-1]) return findKth(nums1, i, nums2, j+k2, k1);
      else return findKth(nums1, i+k1, nums2, j, k2);
    }
};
