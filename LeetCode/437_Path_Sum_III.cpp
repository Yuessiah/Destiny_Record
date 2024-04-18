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
    int pathSum(TreeNode* root, int targetSum) {
      unordered_map<long long, int> freq{{0, 1}};
      if (root != NULL) return pathPre(root, 0, freq, targetSum);
      else return 0;
    }

    int pathPre(TreeNode* u, long long pre, unordered_map<long long, int> freq, int k) {
      pre += u->val;

      int cnt = 0;
      if (freq.count(pre-k)) cnt += freq[pre-k];
      freq[pre]++;

      if (u->left  != NULL) cnt += pathPre(u->left , pre, freq, k);
      if (u->right != NULL) cnt += pathPre(u->right, pre, freq, k);

      return cnt;
    }
};
