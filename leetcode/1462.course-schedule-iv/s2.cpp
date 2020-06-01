// OJ: https://leetcode.com/problems/course-schedule-iv/
// Author: github.com/elaijuh
// Time: O(K*(N+E)) K=queries.size()
// Space: O(N^2)

// DFS + memoization
class Solution {
  vector<vector<int>> dp;

 public:
  bool dfs(vector<vector<int>>& al, int v, int u) {
    if (dp[v][u] != -1) return dp[v][u];
    for (int x : al[v]) {
      if (x == u || dfs(al, x, u)) return dp[v][u] = 1;
    }
    return dp[v][u] = 0;
  }
  vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites,
                                   vector<vector<int>>& queries) {
    dp.resize(n, vector<int>(n, -1));
    vector<vector<int>> al(n);
    for (auto e : prerequisites) {
      al[e[0]].push_back(e[1]);
      dp[e[0]][e[1]] = 1;
    }
    vector<bool> ans;
    for (auto x : queries) ans.push_back(dfs(al, x[0], x[1]));
    return ans;
  }
};
