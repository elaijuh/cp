#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int minDeletionSize(vector<string> &strs)
	{
		int m = strs[0].size();
		vector<int> dp(m, 1);
		for (int i = m - 2; i >= 0; --i) {
			for (int j = i + 1; j < m; ++j) {
				bool sorted = true;
				for (auto &s : strs) {
					if (s[i] > s[j]) sorted = false;
				}
				if (sorted) dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		int mx = 0;
		for (int x : dp) mx = max(mx, x);
		return m - mx;
	}
};
