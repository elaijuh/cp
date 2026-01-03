#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int findMaxVal(int n, vector<vector<int>> &restrictions, vector<int> &diff)
	{
		vector<int> ans(n, INT_MAX);
		for (auto &r : restrictions) {
			ans[r[0]] = r[1];
		}
		ans[0] = 0;
		// left to right
		for (int i = 1; i < n; ++i) {
			int next = ans[i - 1] + diff[i - 1];
			if (next > ans[i]) continue;
			ans[i] = next;
		}
		// right to left
		for (int i = n - 2; i >= 0; --i) {
			int next = ans[i + 1] + diff[i];
			ans[i] = min(ans[i], next);
		}
		return *max_element(ans.begin(), ans.end());
	}
};
