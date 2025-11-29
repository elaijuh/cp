#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> findErrorNums(vector<int> &nums)
	{
		vector<int> res;
		sort(nums.begin(), nums.end());
		int n = nums.size();
		int dup = 0, k = nums[0];
		for (int i = 1; i < n; ++i) {
			if (nums[i] == nums[i - 1])
				dup = nums[i];
			k += nums[i];
		}
		res.push_back(dup);
		res.push_back((1 + n) * n / 2 - k + dup);
		return res;
	}
}
