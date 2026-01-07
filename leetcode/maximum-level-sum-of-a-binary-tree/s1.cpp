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
	int maxLevelSum(TreeNode *root)
	{
		vector<int> v;
		queue<TreeNode *> q;
		q.push(root);
		while (!q.empty()) {
			int sum = 0;
			int qsize = q.size();
			for (int i = 0; i < qsize; ++i) {
				TreeNode *node = q.front();
				q.pop();
				sum += node->val;
				if (node->left) q.push(node->left);
				if (node->right) q.push(node->right);
			}
			v.push_back(sum);
		}
		return max_element(v.begin(), v.end()) - v.begin() + 1;
	}
}
