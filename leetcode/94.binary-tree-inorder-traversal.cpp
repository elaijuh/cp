/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
  vector<int> a;

 public:
  vector<int> inorderTraversal(TreeNode* root) {
    if (root == NULL) return a;
    inorderTraversal(root->left);
    a.push_back(root->val);
    inorderTraversal(root->right);
    return a;
  }
};
