// OJ: https://leetcode.com/problems/unique-paths/
// Author: github.com/elaijuh
// Time: O(m*n)
// Space: O(n)
class Solution {
 public:
  int uniquePaths(int m, int n) {
    vector<int> dp(n, 1);
    while (--m)
      for (int i = 1; i < n; ++i) dp[i] += dp[i - 1];
    return dp[n - 1];
  }
};
