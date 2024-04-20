/*
class Solution {
  public:
    string largestNumber(vector<int>& nums) {
      sort(nums.begin(), nums.end(), [](int a, int b) {
        if (!a || !b) return a > b;

        long long an = 1, bn = 1, aa = a, bb = b;
        while (aa > 0) aa /= 10, an *= 10;
        while (bb > 0) bb /= 10, bn *= 10;

        while (an != bn) {
          if (an > bn) {
            an /= bn;
            if (a / an != b) return a/an > b;
            a %= an;
          } else {
            bn /= an;
            if (b / bn != a) return a > b/bn;
            b %= bn;
          }
        }

        return a > b;
      });

      if (!nums[0]) return "0";

      string ans;
      for (int x: nums)
        ans += to_string(x);
      return ans;
    }
};
*/

class Solution {
  public:
    string largestNumber(vector<int>& nums) {
      sort(nums.begin(), nums.end(), [](int a, int b) {
          return to_string(a)+to_string(b) > to_string(b)+to_string(a);
          });

      if (!nums[0]) return "0";

      string ans;
      for (int x: nums) ans += to_string(x);
      return ans;
    }
};
