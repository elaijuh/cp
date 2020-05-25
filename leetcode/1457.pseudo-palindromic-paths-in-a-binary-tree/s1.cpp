// OJ: https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/
// Author: github.com/elaijuh
// Time: O()
// Space: O()
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
  int m[10] = {0};
  int ans = 0;

 public:
  bool isPalindromic() {
    int cnt = 0;
    for (int i = 1; i <= 9; ++i) {
      if (m[i] % 2 != 0) cnt++;
    }
    return cnt <= 1;
  }
  void dfs(TreeNode* r, TreeNode* parent) {
    if (!r->left && !r->right) {
      m[r->val]++;
      if (isPalindromic()) ans++;
      m[r->val]--;
      return;
    }
    m[r->val]++;
    if (r->left) dfs(r->left, r);
    if (r->right) dfs(r->right, r);
    m[r->val]--;
  }
  int pseudoPalindromicPaths(TreeNode* root) {
    dfs(root, nullptr);
    return ans;
  }
};
