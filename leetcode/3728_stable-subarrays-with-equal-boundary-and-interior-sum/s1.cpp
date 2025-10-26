#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	using ll = long long;
	long long countStableSubarrays(vector<int> &capacity)
	{
		int n = capacity.size();
		ll ans = 0, pre = 0;
		unordered_map<int, unordered_map<ll, ll>> mp;
		for (int i = 0; i < n; ++i) {
			if (mp.count(capacity[i]) && mp[capacity[i]].count(pre - capacity[i]))
				ans += mp[capacity[i]][pre - capacity[i]];
			pre += capacity[i];
			mp[capacity[i]][pre]++;
			if (i > 0 && capacity[i] == 0 && capacity[i - 1] == 0)
				ans--;
		}
		return ans;
	}
};
