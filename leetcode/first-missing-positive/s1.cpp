#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int firstMissingPositive(vector<int> &nums)
	{
		int n = nums.size();
		bool hasone = false;
		for (int i = 0; i < n; ++i) {
			if (nums[i] == 1)
				hasone = true;
			else if (nums[i] <= 0 || nums[i] > n)
				nums[i] = 1;
		}
		if (!hasone) return 1;
		for (int i = 0; i < n; ++i) {
			int v = abs(nums[i]);
			if (v == n)
				nums[0] = -abs(nums[0]);
			else
				nums[v] = -abs(nums[v]);
		}
		for (int i = 1; i < n; ++i)
			if (nums[i] > 0) return i;
		if (nums[0] > 0) return n;
		return n + 1;
	}
};
