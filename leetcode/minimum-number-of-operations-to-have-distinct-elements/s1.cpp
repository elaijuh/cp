#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int minOperations(vector<int> &nums)
	{
		unordered_map<int, int> mp;
		for (int &x : nums) mp[x]++;
		int n = nums.size();
		int ans = 0;
		if (mp.size() == n)
			return ans;

		for (int i = 0; i < n; ++i) {
			mp[nums[i]]--;
			if (mp[nums[i]] == 0)
				mp.erase(nums[i]);
			if (mp.size() == n - i - 1) {
				ans++;
				break;
			}
			if ((i + 1) % 3 == 0)
				ans++;
		}
		return ans;
	}
};
