// OJ: https://leetcode.com/problems/possible-bipartition/
// Author: github.com/elaijuh
// Time: O(N+E)
// Space: O(N+E)

// Bipartite graph
// DFS
class Solution {
 public:
  unordered_map<int, int> m;
  vector<vector<int>> G;
  bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
    G.resize(N + 1);
    for (auto x : dislikes) {
      G[x[0]].push_back(x[1]);
      G[x[1]].push_back(x[0]);
    }
    for (int i = 1; i <= N; ++i)
      if (m.find(i) == m.end() && !dfs(i, 0)) return false;
    return true;
  }
  bool dfs(int n, int c) {
    if (m.find(n) != m.end()) return m[n] == c;
    m[n] = c;
    for (auto x : G[n]) {
      if (!dfs(x, c ^ 1)) return false;
    }
    return true;
  }
};
