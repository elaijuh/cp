// OJ: https://leetcode.com/problems/kth-smallest-element-in-a-bst/
// Author: github.com/elaijuh
// Time: O(nlogn)
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
 public:
  int ans;
  int dfs(TreeNode* n, int k) {
    if (!n) return 0;
    if (k == 1) {
      ans = n->val;
    }
    int lk = dfs(n->left, k - 1);
    int rk = dfs(n->right, k - lk - 1);
    return lk + rk + 1;
  }
  int kthSmallest(TreeNode* root, int k) {
    dfs(root, k);
    return ans;
  }
};
