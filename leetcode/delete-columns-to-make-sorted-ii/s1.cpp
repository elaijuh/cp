#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int minDeletionSize(vector<string> &strs)
	{
		int n = strs.size(), m = strs[0].size();
		bitset<100> r_sorted;
		int ans = 0;
		for (int i = 0; i < m; ++i) {
			bool is_del = false;
			for (int j = 0; j < n - 1; ++j) {
				if (!r_sorted[j] & strs[j][i] > strs[j + 1][i]) {
					is_del = true;
					ans++;
					break;
				}
			}
			if (is_del) continue;
			for (int j = 0; j < n - 1; ++j) {
				r_sorted[j] = r_sorted[j] | strs[j][i] < strs[j + 1][i];
			}
		}
		return ans;
	}
};
