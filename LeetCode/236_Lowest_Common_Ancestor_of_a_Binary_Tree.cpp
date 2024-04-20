/*
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
  public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      return findLCA(root, p, q);
    }

    TreeNode* findLCA(TreeNode* u, TreeNode* p, TreeNode* q) {
      TreeNode *L, *R;
      L = R = NULL;
      if (u->left  != NULL) L = findLCA(u->left , p, q);
      if (u->right != NULL) R = findLCA(u->right, p, q);

      if (L != NULL && R != NULL) {
        if (L == p && R == q) return u;
        if (L == q && R == p) return u;
      }

      if (u == p) return p;
      if (u == q) return q;
      if (L != NULL) return L;
      if (R != NULL) return R;

      return NULL;
    }
};
