// OJ: https://leetcode.com/problems/count-complete-tree-nodes/
// Author: github.com/elaijuh
// Time: O(log(n)^2)
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
  int countNodes(TreeNode* root) {
    int h = height(root);
    if (h < 0) return 0;
    int rightHeight = height(root->right);
    if (rightHeight == h - 1) {
      return (1 << h) + countNodes(root->right);
    } else {
      return (1 << (h - 1)) + countNodes(root->left);
    }
  }
  int height(TreeNode* root) {
    if (!root)
      return -1;
    else
      return 1 + height(root->left);
  }
};
