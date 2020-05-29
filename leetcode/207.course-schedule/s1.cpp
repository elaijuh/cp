// OJ: https://leetcode.com/problems/course-schedule/
// Author: github.com/elaijuh
// Time: O(N+E)
// Space: O(N+E)
class Solution {
 public:
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adj(numCourses);
    vector<int> idegree(numCourses, 0);
    vector<int> odegree(numCourses, 0);
    for (auto e : prerequisites) {
      adj[e[1]].push_back(e[0]);
      idegree[e[0]]++;
      odegree[e[1]]++;
    }
    queue<int> q;
    for (int i = 0; i < numCourses; ++i)
      if (idegree[i] == 0) q.push(i);
    int vs = numCourses;
    while (!q.empty()) {
      int v = q.front();
      q.pop();
      vs--;
      if (odegree[v] > 0) {
        for (int u : adj[v]) {
          idegree[u]--;
          odegree[v]--;
          if (idegree[u] == 0) q.push(u);
        }
      }
    }
    if (vs != 0) return false;
    return true;
  }
};
