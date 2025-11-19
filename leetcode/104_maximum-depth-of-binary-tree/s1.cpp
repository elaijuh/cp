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
	int maxDepth(TreeNode *root)
	{
		if (!root)
			return 0;
		stack<pair<TreeNode *, int>> stk;
		stk.push({root, 1});
		int ans = 0;
		while (!stk.empty()) {
			auto it = stk.top();
			TreeNode *no = it.first;
			stk.pop();
			ans = max(ans, it.second);
			if (no->left)
				stk.push({no->left, it.second + 1});
			if (no->right)
				stk.push({no->right, it.second + 1});
		}
		return ans;
	}
};
