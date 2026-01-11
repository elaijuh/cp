#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int> &nums, int target)
	{
		unordered_map<int, int> mp;
		vector<int> ans;
		for (int i = 0; i < nums.size(); ++i) {
			if (mp.count(target - nums[i]) && mp[target - nums[i]] != i) {
				ans = {i, mp[target - nums[i]]};
				break;
			}
			else {
				mp[nums[i]] = i;
			}
		}
		return ans;
	}
};
