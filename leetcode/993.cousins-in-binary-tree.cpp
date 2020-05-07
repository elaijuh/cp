/*
 * @lc app=leetcode id=993 lang=cpp
 *
 * [993] Cousins in Binary Tree
 *
 * https://leetcode.com/problems/cousins-in-binary-tree/description/
 *
 * algorithms
 * Easy (52.23%)
 * Likes:    617
 * Dislikes: 33
 * Total Accepted:    64.6K
 * Total Submissions: 122.1K
 * Testcase Example:  '[1,2,3,4]\n4\n3'
 *
 * In a binary tree, the root node is at depth 0, and children of each depth k
 * node are at depth k+1.
 *
 * Two nodes of a binary tree are cousins if they have the same depth, but have
 * different parents.
 *
 * We are given the root of a binary tree with unique values, and the values x
 * and y of two different nodes in the tree.
 *
 * Return true if and only if the nodes corresponding to the values x and y are
 * cousins.
 *
 *
 *
 * Example 1:
 *
 *
 *
 * Input: root = [1,2,3,4], x = 4, y = 3
 * Output: false
 *
 *
 *
 * Example 2:
 *
 *
 *
 * Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
 * Output: true
 *
 *
 *
 * Example 3:
 *
 *
 *
 *
 * Input: root = [1,2,3,null,4], x = 2, y = 3
 * Output: false
 *
 *
 *
 *
 *
 * Note:
 *
 *
 * The number of nodes in the tree will be between 2 and 100.
 * Each node has a unique integer value from 1 to 100.
 *
 *
 *
 *
 *
 *
 *
 */

// @lc code=start
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
  int xd;
  int yd;
  int xp;
  int yp;

  void traverse(TreeNode* p, int x, int y, int depth, int parent) {
    if (!p) return;
    if (p->val == x) {
      xd = depth;
      xp = parent;
    } else if (p->val == y) {
      yd = depth;
      yp = parent;
    }
    traverse(p->left, x, y, depth + 1, p->val);
    traverse(p->right, x, y, depth + 1, p->val);
  }

  bool isCousins(TreeNode* root, int x, int y) {
    traverse(root, x, y, 0, -1);
    return xd == yd && xp != yp ? true : false;
  }
};
// @lc code=end
