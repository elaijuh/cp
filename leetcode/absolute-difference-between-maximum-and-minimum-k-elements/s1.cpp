#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int absDifference(vector<int> &nums, int k)
	{
		sort(nums.begin(), nums.end());
		int l = 0, r = 0;
		int n = nums.size();
		for (int i = 0; i < k; ++i) {
			l += nums[i];
			r += nums[n - i - 1];
		}
		return r - l;
	}
}
