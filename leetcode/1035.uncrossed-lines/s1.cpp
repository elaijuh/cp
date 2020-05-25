// OJ: https://leetcode.com/problems/uncrossed-lines/
// Author: github.com/elaijuh
// Time: O(mn)
// Space: O(mn)
// LCS
class Solution {
 public:
  int maxUncrossedLines(vector<int>& A, vector<int>& B) {
    int dp[501][501] = {0};
    int na = A.size(), nb = B.size();
    for (int i = 1; i <= na; ++i)
      for (int j = 1; j <= nb; ++j) {
        if (A[i - 1] == B[j - 1])
          dp[i][j] = dp[i - 1][j - 1] + 1;
        else
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    return dp[na][nb];
  }
};
