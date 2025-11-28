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
	TreeNode *pick(const vector<int> &v, int l, int r)
	{
		if (l >= r)
			return nullptr;
		int m = (l + r) / 2;
		TreeNode *p = new TreeNode(v[m], pick(v, l, m), pick(v, m + 1, r));
		return p;
	}

	TreeNode *sortedArrayToBST(vector<int> &nums)
	{
		int n = nums.size();
		return pick(nums, 0, n);
	}
}
