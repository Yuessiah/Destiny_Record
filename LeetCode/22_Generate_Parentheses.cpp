class Solution {
  public:
    Solution() {
      ans[1].push_back("()");
    }

    vector<string> generateParenthesis(int n) {
      for (int i = 2; i <= n; i++) {
        set<string> nans;

        for(string s: ans[i-1])
          nans.insert(string("(") + s + ')');

        for (int j = 1; j <=i/2; j++) {
          for (string s1: ans[j])
            for (string s2: ans[i-j]) {
              nans.insert(s1 + s2);
              nans.insert(s2 + s1);
            }
        }

        ans[i].assign(nans.begin(), nans.end());
      }

      return ans[n];
    }

  private:
    vector<string> ans[10];
};
