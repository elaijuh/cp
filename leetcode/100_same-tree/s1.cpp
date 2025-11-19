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
	bool isSameTree(TreeNode *p, TreeNode *q)
	{
		if (!p && !q)
			return true;
		stack<TreeNode *> sp, sq;
		sp.push(p);
		sq.push(q);
		while (!sp.empty() && !sq.empty()) {
			TreeNode *np = sp.top();
			TreeNode *nq = sq.top();
			sp.pop();
			sq.pop();
			if (np && !nq)
				return false;
			if (!np && nq)
				return false;
			if (np && nq && np->val != nq->val)
				return false;
			if (np) {
				sp.push(np->left);
				sp.push(np->right);
			}
			if (nq) {
				sq.push(nq->left);
				sq.push(nq->right);
			}
		}
		return true;
	}
};
