/*
 * @lc app=leetcode id=375 lang=cpp
 *
 * [375] Guess Number Higher or Lower II
 */

// tag: dp

class Solution {
 public:
  int getMoneyAmount(int n) {
    // dp[i][j] is the amount for guessing the number from i to j
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    return helper(1, n, dp);
  }

  int helper(int l, int r, vector<vector<int>> &dp) {
    if (l >= r) return 0;
    if (dp[l][r] > 0) return dp[l][r];

    int res = INT_MAX;
    for (int k = l; k <= r; k++) {
      int t = k + max(helper(l, k - 1, dp), helper(k + 1, r, dp));
      res = min(res, t);
    }
    return dp[l][r] = res;
  }
};
