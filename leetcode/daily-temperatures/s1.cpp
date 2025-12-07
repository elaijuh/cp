#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> dailyTemperatures(vector<int> &temperatures)
	{
		int n = temperatures.size();
		vector<int> ans(n, 0);
		vector<int> st;
		for (int i = 0; i < n; ++i) {
			while (!st.empty()) {
				int t = st.back();
				if (temperatures[i] > temperatures[t]) {
					ans[t] = i - t;
					st.pop_back();
					continue;
				}
				break;
			}
			st.push_back(i);
		}
		return ans;
	}
};
