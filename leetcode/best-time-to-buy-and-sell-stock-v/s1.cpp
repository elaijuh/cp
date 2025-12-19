#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	typedef long long ll;

	ll dp[1000][501][3];

	void p(ll v[][501][3], int n, int k)
	{
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j <= k; ++j) {
				auto [c, b, s] = v[i][j];
				cout << c << " " << b << " " << s;
			}
			cout << "\n";
		}
	}

	long long maximumProfit(vector<int> &prices, int k)
	{
		int n = prices.size();
		for (int i = 0; i < k + 1; ++i) {
			dp[0][i][0] = 0;
			dp[0][i][1] = -prices[0];
			dp[0][i][2] = prices[0];
		}

		for (int i = 1; i < n; ++i) {
			int x = prices[i];
			for (int j = 1; j <= k; ++j) {
				auto [c, b, s] = dp[i - 1][j];
				ll pre = dp[i - 1][j - 1][0];
				c = max(c, max(b + x, s - x));
				b = max(b, pre - x);
				s = max(s, pre + x);
				dp[i][j][0] = c;
				dp[i][j][1] = b;
				dp[i][j][2] = s;
			}
		}
		return dp[n - 1][k][0];
	}
};
