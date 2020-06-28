// OJ: https://leetcode.com/problems/perfect-squares/
// Author: github.com/elaijuh
// Time: O(n*sqrt(n))
// Space: O(n)
class Solution {
 public:
  int numSquares(int n) {
    vector<int> dp(n + 1, n);
    dp[0] = 0;  //基问题
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j * j <= i; ++j)
        dp[i] = min(dp[i], 1 + dp[i - j * j]);  // 子问题
    return dp[n];
  }
};
