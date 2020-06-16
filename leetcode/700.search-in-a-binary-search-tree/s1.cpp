// OJ: https://leetcode.com/problems/search-in-a-binary-search-tree/
// Author: github.com/elaijuh
// Time: O(logn)
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
  TreeNode* searchBST(TreeNode* root, int val) {
    TreeNode* p = root;
    while (p) {
      if (val < p->val)
        p = p->left;
      else if (p->val < val)
        p = p->right;
      else
        return p;
    }
    return NULL;
  }
};
