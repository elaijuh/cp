/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */

// BFS, DFS

class Solution {
 public:
  int numIslands(vector<vector<char>>& grid) {
    const int m = grid.size();
    if (m == 0) return 0;
    const int n = grid[0].size();
    vector<vector<int>> d = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int ans = 0;
    queue<pair<int, int>> q;
    for (int x = 0; x < m; x++)
      for (int y = 0; y < n; y++) {
        if (grid[x][y] == '0') continue;
        q.push({x, y});
        grid[x][y] = '0';
        while (!q.empty()) {
          auto p = q.front();
          q.pop();
          for (int i = 0; i < 4; i++) {
            int ii = p.first + d[i][0];
            int jj = p.second + d[i][1];
            if (ii >= 0 && ii < m && jj >= 0 && jj < n && grid[ii][jj] == '1') {
              q.push({ii, jj});
              grid[ii][jj] = '0';
            }
          }
        }
        ans++;
      }
    return ans;
  }
};
