class Solution {
  public:
    string minWindow(string s, string t) {
      unordered_map<char, int> freq;
      for (int c: t) freq[c]++;

      int i = 0, j = 0, cnt = 0, ansi = -1, ansl = s.length();
      while (j < s.length()) {
        if (freq.count(s[j]) && freq[s[j]]-- > 0) cnt++;
        j++;

        while (i < j && cnt == t.length()) {
          if (ansl >= j-i) ansi = i, ansl = j-i;
          if (freq.count(s[i]) && ++freq[s[i]] > 0) cnt--;
          i++;
        }
      }

      return ~ansi? s.substr(ansi, ansl) : "";
    }
};
