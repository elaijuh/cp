#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int> &nums)
	{
		vector<int> a = {nums[0]};
		int n = nums.size();
		for (int i = 1; i < n; ++i)
			if (nums[i] != nums[i - 1])
				a.push_back(nums[i]);
		nums = a;
		return a.size();
	}
};
