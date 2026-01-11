#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
	TreeNode *ans;
	int ma = 0;
	int dfs(TreeNode *node, int height)
	{
		if (!node) return height;
		int l = dfs(node->left, height + 1);
		int r = dfs(node->right, height + 1);
		if (l == r && l >= ma) {
			ma = l;
			ans = node;
		}
		return max(l, r);
	}

	TreeNode *subtreeWithAllDeepest(TreeNode *root)
	{
		dfs(root, 1);
		return ans;
	}
};
