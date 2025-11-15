#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool canJump(vector<int> &nums)
	{
		// return s1(nums);
		return s2(nums);
	}

	// greedy
	bool s1(vector<int> &nums)
	{
		int n = nums.size();
		int m = 0;
		for (int i = 0; i < n; ++i) {
			if (i > m)
				return false;
			m = max(m, i + nums[i]);
		}
		return true;
	}

	// dp
	bool s2(vector<int> &nums)
	{
		int n = nums.size();
		vector<bool> dp(n, false);
		dp[n - 1] = true;
		int target = n - 1;
		for (int i = n - 2; i >= 0; --i) {
			if (i + nums[i] >= target) {
				dp[i] = true;
				target = i;
			}
		}
		return dp[0];
	}
};
