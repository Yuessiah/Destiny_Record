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
    bool isValidBST(TreeNode* root) {
      bool ok = true;
      if (root->right != NULL) {
        TreeNode* mn = root->right;
        while (mn->left != NULL) mn = mn->left;

        if (root->val >= mn->val) return false;
        else ok &= isValidBST(root->right);
      }

      if (root->left != NULL) {
        TreeNode* mx = root->left;
        while (mx->right != NULL) mx = mx->right;

        if (root->val <= mx->val) return false;
        else ok &= isValidBST(root->left);
      }

      return ok;
    }
};
