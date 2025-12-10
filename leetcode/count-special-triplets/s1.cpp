#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int specialTriplets(vector<int> &nums)
	{
		int mod = 1'000'000'007;
		unordered_map<int, int> left, total;
		int n = nums.size();
		int ans = 0;
		for (int i = 0; i < n; ++i) total[nums[i]]++;
		left[nums[0]]++;

		for (int i = 1; i < n - 1; ++i) {
			int t = nums[i] * 2;
			ans = (ans + left[t] * 1LL * (t == 0 ? total[t] - left[t] - 1 : total[t] - left[t]) % mod) % mod;
			left[nums[i]]++;
		}
		return ans;
	}
}
