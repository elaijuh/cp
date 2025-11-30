#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int rev(int n)
	{
		int res = 0;
		while (n != 0) {
			res = res * 10 + n % 10;
			n /= 10;
		}
		return res;
	}

	int minMirrorPairDistance(vector<int> &nums)
	{
		unordered_map<int, int> mp;
		int n = nums.size();
		int res = 100001;
		for (int i = 0; i < n; ++i) {
			if (mp.count(nums[i]))
				res = min(res, abs(i - mp[nums[i]]));
			mp[rev(nums[i])] = i;
		}
		return res == 100001 ? -1 : res;
	}
};
