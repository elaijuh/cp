#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<string> summaryRanges(vector<int> &nums)
	{
		vector<string> res;
		int n = nums.size();
		if (n == 0)
			return res;
		if (n == 1) {
			res.push_back(to_string(nums[0]));
		}
		else {
			int l = nums[0];
			for (int i = 1; i < n; ++i) {
				if (nums[i] > nums[i - 1] + 1) {
					res.push_back(l == nums[i - 1] ? to_string(l) : to_string(l) + "->" + to_string(nums[i - 1]));
					l = nums[i];
				}
			}
			res.push_back(l == nums[n - 1] ? to_string(l) : to_string(l) + "->" + to_string(nums[n - 1]));
		}
		return res;
	}
};
