#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int maxBalancedSubarray(vector<int> &nums)
	{
		unordered_map<int, unordered_map<int, int>> mp;
		int n = nums.size(), xr = 0, odds = 0, res = 0;
		mp[0][0] = -1;
		for (int i = 0; i < n; ++i) {
			xr ^= nums[i];
			odds += (nums[i] & 1 ? 1 : -1);
			if (mp.count(xr) && mp[xr].count(odds)) {
				res = max(res, i - mp[xr][odds]);
			}
			else {
				mp[xr][odds] = i;
			}
		}
		return res;
	}
}
