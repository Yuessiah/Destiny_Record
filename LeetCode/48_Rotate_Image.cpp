class Solution {
  public:
    void rotate(vector<vector<int>>& matrix) {
      int n = matrix.size();
      for (int i = 0; i < n/2; i++)
        for (int j = 0; j < n/2+n%2; j++) {
          int x = matrix[i][j];
          matrix[i][j] = matrix[n-1-j][i];
          matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
          matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
          matrix[j][n-1-i] = x;
        }
    }
};
