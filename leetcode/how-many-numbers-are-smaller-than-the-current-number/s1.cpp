#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> smallerNumbersThanCurrent(vector<int> &nums)
	{
		vector<int> v(nums);
		vector<int> res;
		unordered_map<int, int> mp;
		sort(v.begin(), v.end());
		int n = nums.size();
		for (int i = 0; i < n; ++i) {
			if (!mp.count(v[i]))
				mp[v[i]] = i;
		}
		for (int i = 0; i < n; ++i) {
			res.push_back(mp[nums[i]]);
		}

		return res;
	}
}
