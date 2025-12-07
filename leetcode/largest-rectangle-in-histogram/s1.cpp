#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int largestRectangleArea(vector<int> &heights)
	{
		int n = heights.size();
		vector<int> nsl(n), nsr(n);
		vector<int> st;
		for (int i = 0; i < n; ++i) {
			while (!st.empty() && heights[st.back()] >= heights[i]) st.pop_back();
			nsl[i] = st.empty() ? -1 : st.back();
			st.push_back(i);
		}
		st.clear();
		for (int i = n - 1; i >= 0; --i) {
			while (!st.empty() && heights[st.back()] >= heights[i]) st.pop_back();
			nsr[i] = st.empty() ? n : st.back();
			st.push_back(i);
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			ans = max(ans, heights[i] * (nsr[i] - nsl[i] - 1));
		}
		return ans;
	}
};
