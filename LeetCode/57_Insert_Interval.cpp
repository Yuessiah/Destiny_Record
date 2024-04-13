class Solution {
  public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
      int& left = newInterval[0], right = newInterval[1];
      for(auto x: intervals) {
        int l = x[0], r = x[1];

        bool use = false;
        if(r >= left && l < left) left = l, use = true;
        if(l <= right && r > right) right = r, use = true;
        if(left <= l && r <= right) use = true;
        if(!use) disjoint[l] = r;
      }
      disjoint[left] = right;

      for(auto& [l, r]: disjoint) {
        vector<int> t{l, r};
        ans.push_back(t);
      }

      return ans;
    }

  private:
    map<int, int> disjoint;
    vector<vector<int>> ans;
};
