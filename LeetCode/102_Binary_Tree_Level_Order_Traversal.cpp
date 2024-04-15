/*
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
  public:
    void dfs(TreeNode* u, int d) {
      if(u == NULL) return;

      if(d >= ans.size()) ans.push_back(vector<int>());
      ans[d].push_back(u->val);

      dfs(u->left, d+1);
      dfs(u->right, d+1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
      dfs(root, 0);
      return ans;
    }

  private:
    vector<vector<int>> ans;
};
