#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int bestClosingTime(string customers)
	{
		int n = customers.size();
		vector<int> pre(n + 1, 0), suf(n + 1, 0);
		for (int i = 1; i <= n; ++i) {
			pre[i] = customers[i - 1] == 'N' ? pre[i - 1] + 1 : pre[i - 1];
			suf[n - i] = customers[n - i] == 'Y' ? suf[n - i + 1] + 1 : suf[n - i + 1];
		}
		int ans, mi = INT_MAX;
		for (int i = n; i >= 0; --i) {
			if (pre[i] + suf[i] <= mi) {
				ans = i;
				mi = pre[i] + suf[i];
			}
		}
		return ans;
	}
};
