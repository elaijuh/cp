/*
 * @lc app=leetcode id=226 lang=cpp
 *
 * [226] Invert Binary Tree
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
    void invert(TreeNode *t) {
        if (t == nullptr || t->left == nullptr && t->right == nullptr) return;
        TreeNode *p = t->left;
        t->left = t->right;
        t->right = p; 
        invert(t->left);
        invert(t->right);
    }
public:
    TreeNode* invertTree(TreeNode* root) {
        invert(root);
        return root;
    }
};

