#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int countNegatives(vector<vector<int>> &grid)
	{
		int m = grid.size(), n = grid[0].size();
		int j = 0, ans = 0;
		for (int i = m - 1; i >= 0; --i) {
			while (j < n && grid[i][j] >= 0) j++;
			ans += (n - j);
		}
		return ans;
	}
};
