// OJ:
// https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/
// Author: github.com/elaijuh
// Time: O(N)
// Space: O(N+E)
class Solution {
 public:
  int dfs(vector<vector<int>>& al, int v, int p) {
    int cnt = 0;
    for (int u : al[v]) {
      if (abs(u) == p) continue;
      cnt += dfs(al, abs(u), v) + (u > 0 ? 1 : 0);
    }
    return cnt;
  }
  int minReorder(int n, vector<vector<int>>& connections) {
    vector<vector<int>> al(n);
    for (auto e : connections) {
      al[e[0]].push_back(e[1]);
      al[e[1]].push_back(-e[0]);  // tricky way to store edage in right
                                  // direction, wont'be counted
    }
    return dfs(al, 0, -1);
  }
};
