class Solution {
  public:
    Solution() {
      ans = 1;
      for (int i = 0; i < 256; i++) pp[i] = -1;
    }

    int lengthOfLongestSubstring(string s) {
      pp[s[0]] = 0;
      for (int i = 0, j = 1; j < s.length(); j++) {
        if (pp[s[j]] != -1) i = max(i, pp[s[j]] + 1);
        pp[s[j]] = j;

        ans = max(ans, j-i+1);
      }

      return s.empty()? 0 : ans;
    }

  private:
    int ans, pp[256]; // pp := previous position
};
