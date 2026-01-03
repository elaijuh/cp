#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int repeatedNTimes(vector<int> &nums)
	{
		int n = nums.size();
		for (int i = 0; i < n; ++i)
			if (i + 1 < n && nums[i] == nums[i + 1] || i + 2 < n && nums[i] == nums[i + 2]) return nums[i];
		return nums[0];
	}
};
