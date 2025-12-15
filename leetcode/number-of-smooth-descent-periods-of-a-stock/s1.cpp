#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	long long getDescentPeriods(vector<int> &prices)
	{
		stack<int> st;
		st.push(prices[0]);
		long long ans = 0, k = 0;
		for (int i = 1; i < prices.size(); ++i) {
			if (prices[i] != st.top() - 1) {
				k = 0;
				while (!st.empty()) {
					st.pop();
					k++;
				}
				ans += ((k + 1) * k) >> 1;
			}
			st.push(prices[i]);
		}
		k = 0;
		while (!st.empty()) {
			st.pop();
			k++;
		}
		ans += ((k + 1) * k) >> 1;
		return ans;
	}
};
