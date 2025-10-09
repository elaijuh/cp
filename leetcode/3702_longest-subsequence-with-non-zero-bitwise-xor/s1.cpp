#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int longestSubsequence(vector<int> &nums)
	{
		int x = nums[0], n = nums.size(), zero = nums[0];
		for (int i = 1; i < n; ++i) {
			x ^= nums[i];
			if (nums[i] != 0)
				zero = 1;
		}
		if (!zero)
			return 0;
		if (x)
			return n;
		else
			return n - 1;
	}
};
