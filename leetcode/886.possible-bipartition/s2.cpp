// OJ: https://leetcode.com/problems/possible-bipartition/
// Author: github.com/elaijuh
// Time: O(N+E)
// Space: O(N+E)

// BFS
class Solution {
 public:
  bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
    vector<vector<int>> G(N + 1);
    for (auto x : dislikes) {
      G[x[0]].push_back(x[1]);
      G[x[1]].push_back(x[0]);
    }
    vector<int> visited(N + 1, -1);
    queue<int> q;
    for (int i = 1; i <= N; ++i) {
      if (visited[i] == -1) {
        visited[i] = 0;
        q.push(i);
        while (!q.empty()) {
          int v = q.front();
          q.pop();
          for (int u : G[v]) {
            if (visited[u] == -1) {
              visited[u] = visited[v] ^ 1;
              q.push(u);
            } else if (visited[u] == visited[v]) {
              return false;
            }
          }
        }
      }
    }
    return true;
  }
};
