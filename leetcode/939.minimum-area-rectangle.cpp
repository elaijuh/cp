/*
 * @lc app=leetcode id=939 lang=cpp
 *
 * [939] Minimum Area Rectangle
 */

// diagnoal approach

class Solution {
 public:
  int minAreaRect(vector<vector<int>>& points) {
    unordered_map<int, set<int>> xmap;
    for (auto& p : points) {
      xmap[p[0]].insert(p[1]);
    }
    int n = points.size();
    int ans = INT_MAX;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        int x1 = points[i][0], y1 = points[i][1];
        int x2 = points[j][0], y2 = points[j][1];
        if (x1 != x2 && y1 != y2 && xmap[x1].count(y2) && xmap[x2].count(y1)) {
          ans = min(ans, abs(x1 - x2) * abs(y1 - y2));
        }
      }
    }
    return ans == INT_MAX ? 0 : ans;
  }
};
