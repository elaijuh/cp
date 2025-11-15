#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int jump(vector<int> &nums)
	{
		int n = nums.size();
		vector<int> dp(n, -1);
		dp[n - 1] = 0;
		int step = 10001;
		for (int i = n - 2; i >= 0; --i) {
			step = 10001;
			for (int j = 1; j <= nums[i]; ++j) {
				if (i + j < n && dp[i + j] != -1)
					step = min(step, dp[i + j]);
			}
			dp[i] = step + 1;
		}
		return dp[0];
	}
};
