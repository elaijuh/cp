// OJ: https://leetcode.com/problems/course-schedule/
// Author: github.com/elaijuh
// Time: O(N+E)
// Space: O(N+E)
class Solution {
 public:
  bool dfs(vector<vector<int>>& adj, vector<int>& vis, int v) {
    if (vis[v] == 1) return false;
    if (vis[v] == 0) {
      vis[v] = 1;  // visited and in dfs path
      for (int u : adj[v])
        if (!dfs(adj, vis, u)) return false;
    }
    vis[v] = 2;  // visited
    return true;
  }

  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adj(numCourses);
    for (auto e : prerequisites) adj[e[1]].push_back(e[0]);
    vector<int> vis(numCourses, 0);
    for (int i = 0; i < numCourses; ++i) {
      if (!dfs(adj, vis, i)) return false;
    }
    return true;
  }
};
