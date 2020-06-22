// OJ: https://leetcode.com/problems/dungeon-game/
// Author: github.com/elaijuh
// Time: O(nm)
// Space: O()
class Solution {
 public:
  int calculateMinimumHP(vector<vector<int>>& dungeon) {
    int n = dungeon.size(), m = dungeon[0].size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MAX));  // dp[i][j] i,j
    dp[n - 1][m] = dp[n][m - 1] =
        1;  //   dp[n-1][m-1]    min(dp[n-1][m], dp[n][m-1])
    for (int i = n - 1; i >= 0; --i)
      for (int j = m - 1; j >= 0; --j) {
        int h = min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j];
        dp[i][j] = h > 0 ? h : 1;
      }
    return dp[0][0];
  }
};
