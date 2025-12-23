#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int maxTwoEvents(vector<vector<int>> &events)
	{
		using et_type = tuple<int, int, int>;
		int n = events.size();
		vector<et_type> et(2 * n);
		for (int i = 0; i < n; ++i) {
			et[i] = et_type(events[i][0], false, events[i][2]);
			et[n + i] = et_type(events[i][1], true, events[i][2]);
		}
		// if start==end, start is before end
		sort(et.begin(), et.end());

		int ans = 0, cmax = 0;
		for (auto &e : et) {
			auto [t, is_end, val] = e;
			if (is_end) {
				cmax = max(cmax, val);
			}
			else {
				ans = max(ans, cmax + val);
			}
		}
		return ans;
	}
};
