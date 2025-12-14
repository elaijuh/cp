#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	typedef long long ll;
	long long minMoves(vector<int> &balance)
	{
		int n = balance.size();
		ll sum = 0;
		int k = -1;
		for (int i = 0; i < n; ++i) {
			if (balance[i] < 0)
				k = i;
			sum += balance[i];
		}
		if (k == -1)
			return 0;
		if (sum < 0)
			return -1;

		long long ans = 0;
		int l = k - 1, r = k + 1, cost = 1, res = -balance[k];
		while (res > 0) {
			l = (l + n) % n;
			r = (r + n) % n;
			int t = min(res, balance[l] + balance[r]);
			ans += 1ll * t * cost;
			res -= t;
			cost++;
			l--;
			r++;
		}
		return ans;
	}
}
