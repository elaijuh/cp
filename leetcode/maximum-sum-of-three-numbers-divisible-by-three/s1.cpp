#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int maximumSum(vector<int> &nums)
	{
		vector<int> v0, v1, v2;
		int n = nums.size();
		sort(nums.begin(), nums.end(), greater<int>());
		for (int i = 0; i < n; ++i) {
			if (nums[i] % 3 == 0)
				v0.push_back(nums[i]);
			else if (nums[i] % 3 == 1)
				v1.push_back(nums[i]);
			else
				v2.push_back(nums[i]);
		}
		int ans = 0;
		if (v0.size() >= 3)
			ans = v0[0] + v0[1] + v0[2];
		if (v1.size() >= 3)
			ans = max(ans, v1[0] + v1[1] + v1[2]);
		if (v2.size() >= 3)
			ans = max(ans, v2[0] + v2[1] + v2[2]);
		if (v0.size() >= 1 && v1.size() >= 1 && v2.size() >= 1)
			ans = max(ans, v0[0] + v1[0] + v2[0]);
		return ans;
	}
};
