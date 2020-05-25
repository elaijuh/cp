// OJ: https://leetcode.com/problems/uncrossed-lines/
// Author: github.com/elaijuh
// Time: O(mn)
// Space: O(min(m,n))
// LCS
class Solution {
 public:
  int maxUncrossedLines(vector<int>& A, vector<int>& B) {
    int n = A.size(), m = B.size();
    if (n > m) swap(m, n), swap(A, B);
    vector<int> dp(n + 1);
    for (int i = 0; i < m; ++i) {
      int prev = 0;
      for (int j = 0; j < n; ++j) {
        int cur = dp[j + 1];
        if (B[i] == A[j])
          dp[j + 1] = prev + 1;
        else
          dp[j + 1] = max(dp[j + 1], dp[j]);
        prev = cur;
      }
    }
    return dp[n];
  }
};
