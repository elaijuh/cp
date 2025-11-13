#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int> &nums, int target)
	{
		unordered_map<int, int> mp;
		int n = nums.size();
		vector<int> ans;
		for (int i = 0; i < n; ++i) {
			if (mp.find(nums[i]) == mp.end())
				mp[target - nums[i]] = i;
			else {
				ans = {mp[nums[i]], i};
				break;
			}
		}
		return ans;
	}
}
