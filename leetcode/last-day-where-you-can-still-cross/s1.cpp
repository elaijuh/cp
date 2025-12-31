#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool dfs(int day, vector<vector<int>> &m)
	{
		int row = m.size(), col = m[0].size();
		stack<pair<int, int>> st;
		for (int i = 0; i < col; ++i) {
			if (m[0][i] > day) st.emplace(0, i);
		}
		vector<vector<bool>> vis(row, vector<bool>(col, false));
		pair<int, int> d[4] = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};
		while (!st.empty()) {
			auto [i, j] = st.top();
			st.pop();
			if (i == row - 1) return true;
			for (int k = 0; k < 4; ++k) {
				int dx = i + d[k].first, dy = j + d[k].second;
				if (dx < 0 || dx >= row || dy < 0 || dy >= col) continue;
				if (!vis[dx][dy] && m[dx][dy] > day) {
					st.emplace(dx, dy);
					vis[dx][dy] = true;
				}
			}
		}
		return false;
	}
	int latestDayToCross(int row, int col, vector<vector<int>> &cells)
	{
		int n = cells.size();
		vector<vector<int>> matrix(row, vector<int>(col, 0));
		int day = 1;
		for (int i = 0; i < n; ++i) matrix[cells[i][0] - 1][cells[i][1] - 1] = day++;
		int l = 0, h = n - 1, ans = 1;
		while (l <= h) {
			int m = l + (h - l) / 2;
			if (dfs(m, matrix)) {
				ans = m;
				l = m + 1;
			}
			else
				h = m - 1;
		}
		return ans;
	}
};
