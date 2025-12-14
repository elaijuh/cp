#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int numberOfWays(string corridor)
	{
		vector<pair<int, int>> v;
		int k = 0, p = -1;
		for (int i = 0; i < corridor.size(); ++i) {
			if (corridor[i] == 'S') {
				k++;
				if (k & 1)
					p = i;
				else
					v.push_back({p, i});
			}
		}
		if (k == 0 || k & 1)
			return 0;

		if (v.size() == 1)
			return 1;
		const int MOD = 1000000007;
		long long ans = 1;
		for (int i = 1; i < v.size(); ++i) {
			ans = ((ans % MOD) * ((v[i].first - v[i - 1].second) % MOD)) % MOD;
		}
		return ans;
	}
}
