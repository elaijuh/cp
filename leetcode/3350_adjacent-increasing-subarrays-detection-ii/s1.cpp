#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int maxIncreasingSubarrays(vector<int> &nums)
	{
		ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
		int p = 0, c = 1, k = 0;
		int n = nums.size();
		for (int i = 1; i < n; ++i) {
			if (nums[i] > nums[i - 1]) {
				c++;
				k = max(k, c / 2);
			}
			else {
				k = max(k, min(p, c));
				p = c;
				c = 1;
			}
		}
		k = max(k, min(p, c));
		return k;
	}
};
