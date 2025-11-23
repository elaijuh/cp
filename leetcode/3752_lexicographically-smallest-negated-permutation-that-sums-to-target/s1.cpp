#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	typedef long long ll;
	vector<int> lexSmallestNegatedPerm(int n, long long target)
	{
		ll sum = 1LL * n * (n + 1) / 2;
		if (llabs(target) > sum || (sum - target) & 1)
			return {};

		// sum of abs to flip from pos to neg
		ll rem = (sum - target) / 2;
		vector<int> v(n);
		vector<bool> neg(n + 1, false);
		// start flip from largest neg
		for (int i = n; i >= 1; --i) {
			if (i <= rem) {
				neg[i] = true;
				rem -= i;
			}
		}
		for (int i = 1; i <= n; ++i) v[i - 1] = neg[i] ? -i : i;
		sort(v.begin(), v.end());
		return v;
	}
};
