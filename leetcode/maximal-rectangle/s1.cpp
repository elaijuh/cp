#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int largest_rec(vector<int> &h)
	{
		int n = h.size();
		vector<int> nsl(n), nsr(n);
		vector<int> st;
		for (int i = 0; i < n; ++i) {
			while (!st.empty() && h[st.back()] >= h[i]) st.pop_back();
			nsl[i] = st.empty() ? -1 : st.back();
			st.push_back(i);
		}
		st.clear();
		for (int i = n - 1; i >= 0; --i) {
			while (!st.empty() && h[st.back()] >= h[i]) st.pop_back();
			nsr[i] = st.empty() ? n : st.back();
			st.push_back(i);
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			ans = max(ans, h[i] * (nsr[i] - nsl[i] - 1));
		}
		return ans;
	}

	int maximalRectangle(vector<vector<char>> &matrix)
	{
		int n = matrix.size(), m = matrix[0].size();
		vector<vector<int>> dp(n, vector<int>(m));
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (i == 0)
					dp[i][j] = matrix[i][j] - '0';
				else if (matrix[i][j] == '1')
					dp[i][j] = dp[i - 1][j] + 1;
				else
					dp[i][j] = 0;
			}
			ans = max(ans, largest_rec(dp[i]));
		}
		return ans;
	}
};
