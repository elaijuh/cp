// OJ: https://leetcode.com/problems/k-closest-points-to-origin/
// Author: github.com/elaijuh
// Time: O(KlogN)
// Space: O(K)
class Solution {
 public:
  vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
    priority_queue<pair<int, int>> maxheap;
    for (int i = 0; i < points.size(); ++i) {
      int dis = points[i][0] * points[i][0] + points[i][1] * points[i][1];
      if (maxheap.size() < K)
        maxheap.push({dis, i});
      else if (dis < maxheap.top().first) {
        maxheap.push({dis, i});
        maxheap.pop();
      }
    }
    vector<vector<int>> ans;
    while (!maxheap.empty()) {
      auto t = maxheap.top();
      ans.push_back(points[t.second]);
      maxheap.pop();
    }
    return ans;
  }
};
