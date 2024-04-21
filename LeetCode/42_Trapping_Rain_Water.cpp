class Solution {
  public:
    int trap(vector<int>& height) {
      int n = height.size(), ans = 0;

      for (int i = 0, mx = 0, cnt = 0; i < n; i++) {
        if (mx > height[i]) {
          cnt += mx - height[i];
        } else {
          mx = height[i];
          ans += cnt;
          cnt = 0;
        }
      }

      for (int i = n-1, mx = 0, cnt = 0; i >= 0; i--) {
        if (mx == height[i]) continue;
        if (mx > height[i]) {
          cnt += mx - height[i];
        } else {
          mx = height[i];
          ans += cnt;
          cnt = 0;
        }
      }

      return ans;
    }
};

