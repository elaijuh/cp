#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int minSwaps(vector<int> &nums, vector<int> &forbidden)
	{
		unordered_map<int, int> freq, bad_pair;
		int n = nums.size(), sum_bad_pair = 0, max_bad_pair = 0;

		for (int i = 0; i < n; ++i) {
			freq[nums[i]]++;
			freq[forbidden[i]]++;
			// count of x in nums + count of x in forbidden > n means no way to swap x
			if (freq[nums[i]] > n || freq[forbidden[i]] > n) return -1;
			if (nums[i] == forbidden[i]) {
				bad_pair[nums[i]]++;
				max_bad_pair = max(max_bad_pair, bad_pair[nums[i]]);
				sum_bad_pair++;
			}
		}
		return max((sum_bad_pair + 1) / 2, max_bad_pair);
	}
};
