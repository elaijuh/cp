// OJ: https://leetcode.com/problems/invert-binary-tree/
// Author: github.com/elaijuh
// Time: O(N)
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
  TreeNode* invertTree(TreeNode* root) {
    if (!root || !root->left && !root->right) return root;
    if (root->left) invertTree(root->left);
    if (root->right) invertTree(root->right);
    swap(root->left, root->right);
    return root;
  }
};
