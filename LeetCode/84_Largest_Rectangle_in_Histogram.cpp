class Solution {
  public:
    int largestRectangleArea(vector<int>& heights) {
      heights.insert(heights.begin(), 0); // dummpy
      heights.push_back(0); // dummpy

      int ans = 0;
      stack<int> ins; // increasing subsequence
      for (int i = 0, j; i < heights.size(); ins.push(i++))
        while (ins.size() && heights[j=ins.top()] > heights[i]) {
          ins.pop();
          ans = max(ans, (i-1-ins.top())*heights[j]);
        }

      return ans;
    }
};
