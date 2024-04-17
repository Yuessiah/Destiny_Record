class Solution {
  public:
    int myAtoi(string s) {
      bool ATOI = false, neg = false;
      long long ans = 0;
      for (int i = 0; i < s.length(); i++) {
        if (!ATOI && isspace(s[i])) continue;
        else ATOI = true;

        if (!isdigit(s[i])) {
          if (s[i] != '-' && s[i] != '+') break;
          else if (i+1 >= s.length() || !isdigit(s[i+1])) break;
          else neg = s[i++]=='-';
        }

        ans = ans*10 + (s[i]-'0');
        if (ans > INT_MAX) return neg? INT_MIN : INT_MAX;

        if (i+1 < s.length() && !isdigit(s[i+1])) break;
      }

      return neg? -ans : ans;
    }
};
