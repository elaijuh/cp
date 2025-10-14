#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool hasIncreasingSubarrays(vector<int> &nums, int k)
	{
		ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
		int p = 0, c = 1, kk = 0;
		int n = nums.size();
		for (int i = 1; i < n; ++i) {
			if (nums[i] > nums[i - 1]) {
				c++;
				if (c >= 2 * k)
					return true;
			}
			else {
				kk = max(kk, min(p, c));
				if (kk >= k)
					return true;
				p = c;
				c = 1;
			}
		}
		kk = max(kk, min(p, c));
		if (kk >= k)
			return true;
		return false;
	}
};
