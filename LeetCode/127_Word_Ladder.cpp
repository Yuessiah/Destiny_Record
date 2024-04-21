class Solution {
  public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
      unordered_map<string, bool> vis;
      for (string s: wordList) vis[s] = false;

      queue<pair<string, int>> q({{beginWord, 1}});
      while (q.size()) {
        auto [u, d] = q.front(); q.pop();
        if (u == endWord) return d;

        for (int i = 0; i < u.length(); i++)
          for (char c = 'a', t = u[i]; c <= 'z'; c++) {
            u[i] = c;
            if (vis.count(u) && !vis[u])
              vis[u] = true, q.push({u, d+1});
            u[i] = t;
          }
      }

      return 0;
    }
};
