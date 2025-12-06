#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> finalPrices(vector<int> &prices)
	{
		vector<pair<int, int>> st;
		for (int i = 0; i < prices.size(); ++i) {
			while (!st.empty()) {
				auto [idx, p] = st.back();
				if (prices[i] <= p) {
					prices[idx] = p - prices[i];
					st.pop_back();
					continue;
				}
				break;
			}
			st.push_back({i, prices[i]});
		}
		return prices;
	}
};
