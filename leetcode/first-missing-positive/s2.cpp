#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int firstMissingPositive(vector<int> &nums)
	{
		int n = nums.size();
		// Use cycle sort to place positive elements smaller than n
		// at the correct index
		for (int i = 0; i < n; ++i) {
			if (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1]) {
				swap(nums[i], nums[nums[i] - 1]);
				i--;
			}
		}
		for (int i = 0; i < n; ++i) {
			if (i + 1 != nums[i]) return i + 1;
		}
		return n + 1;
	}
};
