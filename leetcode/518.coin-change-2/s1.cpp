// OJ: https://leetcode.com/problems/coin-change-2/
// Author: github.com/elaijuh
// Time: O(NM)
// Space: O(NM)
class Solution {
  int ans = 0;

 public:
  int change(int amount, vector<int>& coins) {
    vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1));
    for (int i = 0; i <= coins.size(); ++i) dp[i][0] = 1;
    for (int i = 1; i <= coins.size(); ++i)
      for (int j = 1; j <= amount; ++j) {
        dp[i][j] = dp[i - 1][j];
        if (coins[i - 1] <= j) dp[i][j] += dp[i][j - coins[i - 1]];
      }
    return dp[coins.size()][amount];
  }
};
