#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	long long minimumCost(string s, string t, int flipCost, int swapCost, int crossCost)
	{
		int n = s.size();
		int a = 0, b = 0;
		long long ans = 0;
		for (int i = 0; i < n; ++i) {
			if (s[i] == '0' && t[i] == '1') a++;
			if (s[i] == '1' && t[i] == '0') b++;
		}
		long long p = min(a, b);
		ans += p * min(swapCost, 2 * flipCost);
		long long r = abs(a - b);
		ans += r / 2 * min(crossCost + swapCost, 2 * flipCost);
		if (r % 2) ans += flipCost;
		return ans;
	}
};
