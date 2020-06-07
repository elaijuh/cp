// OJ: https://leetcode.com/problems/coin-change-2/
// Author: github.com/elaijuh
// Time: O(NM)
// Space: O(N)
class Solution {
  int ans = 0;

 public:
  int change(int amount, vector<int>& coins) {
    vector<int> dp(amount + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < coins.size(); ++i)
      for (int j = 1; j <= amount; ++j) {
        if (coins[i] <= j) dp[j] += dp[j - coins[i]];
      }
    return dp[amount];
  }
};
