#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int numMagicSquaresInside(vector<vector<int>> &grid)
	{
		int n = grid.size(), m = grid[0].size();
		if (n < 3 || m < 3) return 0;
		int ans = 0;
		for (int i = 1; i < n - 1; ++i) {
			for (int j = 1; j < m - 1; ++j) {
				int c = grid[i][j], ul = grid[i - 1][j - 1], u = grid[i - 1][j], ur = grid[i - 1][j + 1], r = grid[i][j + 1], br = grid[i + 1][j + 1], b = grid[i + 1][j], bl = grid[i + 1][j - 1], l = grid[i][j - 1];
				if (c != 5) continue;
				if (ul & 1 || ur & 1 || br & 1 || bl & 1) continue;
				if (ul + br != 10 || ur + bl != 10 || ul == ur || ul == bl) continue;
				if (ul + u + ur != 15 || ur + r + br != 15 || br + b + bl != 15 || bl + l + ul != 15) continue;
				ans++;
			}
		}
		return ans;
	}
};
