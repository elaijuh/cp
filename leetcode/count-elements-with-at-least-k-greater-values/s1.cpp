#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int countElements(vector<int> &nums, int k)
	{
		sort(nums.begin(), nums.end());
		int n = nums.size();
		int p = nums[0], r = 0, res = 0;
		for (int i = 0; i < n; ++i) {
			if (nums[i] == p) {
				r++;
				continue;
			}
			else {
				if (n - i >= k)
					res += r;
				p = nums[i];
				r = 1;
			}
		}
		if (k == 0)
			res += r;
		return res;
	}
};
