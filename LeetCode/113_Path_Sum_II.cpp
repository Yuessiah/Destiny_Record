/**
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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
      if (root != NULL) Sum(root, targetSum);
      return ans;
    }

    void Sum(TreeNode* u, int t) {
      path.push_back(u->val);
      if (u->left  != NULL) Sum(u->left , t-u->val);
      if (u->right != NULL) Sum(u->right, t-u->val);
      if (u->right == NULL && u->left == NULL && t-u->val == 0) ans.push_back(path);
      path.pop_back();
    }

  private:
    vector<vector<int>> ans;
    vector<int> path;
};
