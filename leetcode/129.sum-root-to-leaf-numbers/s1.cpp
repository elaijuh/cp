// OJ: https://leetcode.com/problems/sum-root-to-leaf-numbers/
// Author: github.com/elaijuh
// Time: O(n)
// Space: O(1)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
 public:
  int ans = 0;
  int sumNumbers(TreeNode* root) {
    if (!root) return 0;
    dfs(root, 0);
    return ans;
  }
  void dfs(TreeNode* p, int s) {
    if (p->left == nullptr && p->right == nullptr)
      ans += p->val + s * 10;
    else {
      if (p->left) dfs(p->left, p->val + s * 10);
      if (p->right) dfs(p->right, p->val + s * 10);
    }
  }
};
