// OJ: https://leetcode.com/problems/cheapest-flights-within-k-stops/
// Author: github.com/elaijuh
// Time: O(ek)
// Space: O()
// DP
class Solution {
 public:
  int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                        int K) {
    vector<vector<int>> dp(
        n, vector<int>(K + 2, INT_MAX));  // dp[i][j] src i j stops
    for (int i = 0; i < K + 2; ++i) dp[src][i] = 0;
    for (int i = 1; i < K + 2; ++i)
      for (auto& f : flights) {
        int u = f[0], v = f[1], w = f[2];
        if (dp[u][i - 1] != INT_MAX) {
          dp[v][i] = min(dp[v][i], dp[u][i - 1] + w);
        }
      }
    return dp[dst][K + 1] == INT_MAX ? -1 : dp[dst][K + 1];
  }
};
