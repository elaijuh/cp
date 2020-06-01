// OJ: https://leetcode.com/problems/course-schedule-iv/
// Author: github.com/elaijuh
// Time: O(N^3)
// Space: O(N^2)

// Floyd-Warshall Algorithm
class Solution {
 public:
  vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites,
                                   vector<vector<int>>& queries) {
    vector<vector<int>> am(n, vector<int>(n, INT_MAX / 2));
    for (auto e : prerequisites) am[e[0]][e[1]] = 1;
    for (int k = 0; k < n; ++k)
      for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
          if (am[i][j] > am[i][k] + am[k][j]) am[i][j] = am[i][k] + am[k][j];
    vector<bool> ans;
    for (auto x : queries)
      ans.push_back(am[x[0]][x[1]] == INT_MAX / 2 ? false : true);
    return ans;
  }
};
