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
	using ll = long long;
	const int MOD = 1e9 + 7;
	ll total = 0;
	ll ans = 0;
	unordered_map<TreeNode *, ll> m;

	ll sum(TreeNode *node)
	{
		if (!node) return 0;
		ll l = sum(node->left);
		ll r = sum(node->right);
		m[node] = l + r + node->val;
		return m[node];
	}

	void sub(TreeNode *node)
	{
		if (!node) return;
		ll s = m[node];
		ans = max(ans, (total - s) * s);
		sub(node->left);
		sub(node->right);
	}

	int maxProduct(TreeNode *root)
	{
		total = sum(root);
		sub(root);
		return ans % MOD;
	}
};
