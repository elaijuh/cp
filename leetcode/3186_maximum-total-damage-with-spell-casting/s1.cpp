#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	long long maximumTotalDamage(vector<int> &power)
	{
		ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
		unordered_map<int, long long> count;
		for (int p : power) {
			count[p]++;
		}
		vector<int> keys;
		for (auto &[k, _] : count)
			keys.push_back(k);
		sort(keys.begin(), keys.end());
		int n = keys.size();
		vector<long long> dp(n);
		dp[0] = keys[0] * count[keys[0]];
		for (int i = 1; i < n; ++i) {
			long long take = keys[i] * count[keys[i]];
			int p = upper_bound(keys.begin(), keys.begin() + i, keys[i] - 3) -
					keys.begin() - 1;
			if (p >= 0)
				take += dp[p];
			dp[i] = max(dp[i - 1], take);
		}
		return dp[n - 1];

		/*
		vector<long long> dp(n, 0);
		long long mx = 0;
		for (int i = 1, j = 1; i < n; i++) {
			while (j < i && keys[j] < keys[i] - 2) {
				mx = max(mx, dp[j]);
				j++;
			}
			dp[i] = mx + 1LL * count[keys[i]] * keys[i];
		}

		long long ans = 0;
		for (int i = 1; i < n; i++) {
			ans = max(ans, dp[i]);
		}
		return ans;
		*/
	}
};
