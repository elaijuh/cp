// OJ: https://leetcode.com/problems/count-square-submatrices-with-all-ones/
// Author: github.com/elaijuh
// Time: O(n^3)
// Space: O()

class Solution {
 public:
  int countSquares(vector<vector<int>>& matrix) {
    int t[301][301];
    for (int i = 0; i < 301; ++i)
      for (int j = 0; j < 301; ++j) t[i][j] = 0;
    int m = matrix.size();
    int n = matrix[0].size();
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        t[i + 1][j + 1] = t[i + 1][j] + t[i][j + 1] - t[i][j] + matrix[i][j];
    int ans = 0;
    for (int i = 1; i <= m; ++i)
      for (int j = 1; j <= n; ++j)
        for (int k = 0; i + k <= m && j + k <= n; ++k) {
          int s = t[i + k][j + k] - t[i - 1][j + k] - t[i + k][j - 1] +
                  t[i - 1][j - 1];
          if (s == (k + 1) * (k + 1)) ans++;
        }
    return ans;
  }
};
