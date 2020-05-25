// OJ:
// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
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
  TreeNode* bstFromPreorder(vector<int>& preorder) {
    TreeNode* root = new TreeNode(preorder[0]);
    for (int i = 1; i < preorder.size(); ++i) {
      TreeNode* p = root;
      TreeNode* t = new TreeNode(preorder[i]);
      while (p) {
        if (preorder[i] < p->val) {
          if (!p->left) {
            p->left = t;
            break;
          }
          p = p->left;
        } else {
          if (!p->right) {
            p->right = t;
            break;
          }
          p = p->right;
        }
      }
    }
    return root;
  }
};
