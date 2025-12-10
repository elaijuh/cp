#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	bool hasPathSum(TreeNode *root, int targetSum)
	{
		if (!root)
			return false;
		stack<pair<TreeNode *, int>> stk;
		stk.push({root, root->val});
		while (!stk.empty()) {
			auto [node, val] = stk.top();
			stk.pop();
			if (!node->left && !node->right && val == targetSum)
				return true;
			if (node->left)
				stk.push({node->left, node->left->val + val});
			if (node->right)
				stk.push({node->right, node->right->val + val});
		}
		return false;
	}
};
