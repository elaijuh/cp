#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int minLength(vector<int> &nums, int k)
	{
		int n = nums.size();
		int s = 0, ans = INT_MAX;
		unordered_map<int, int> used;
		for (int i = 0, j = 0; j < n; ++j) {
			if (used[nums[j]] == 0) s += nums[j];
			used[nums[j]]++;
			while (i <= j && s >= k) {
				if (i == j) return 1;
				ans = min(ans, j - i + 1);
				if (used[nums[i]] == 1) s -= nums[i];
				used[nums[i]]--;
				i++;
			}
		}
		return ans == INT_MAX ? -1 : ans;
	}
};
