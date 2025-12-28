#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	using ll = long long;
	long long maximumHappinessSum(vector<int> &happiness, int k)
	{
		sort(happiness.begin(), happiness.end(), greater<int>());
		ll ans = 0;
		for (int i = 0; i < k; ++i) ans += (happiness[i] - i > 0 ? happiness[i] - i : 0);
		return ans;
	}
};
