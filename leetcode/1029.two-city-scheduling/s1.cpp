// OJ: https://leetcode.com/problems/two-city-scheduling/
// Author: github.com/elaijuh
// Time: O()
// Space: O()
class Solution {
 public:
  int twoCitySchedCost(vector<vector<int>>& costs) {
    sort(costs.begin(), costs.end(),
         [&](const vector<int>& a, const vector<int>& b) -> bool {
           return a[1] - a[0] > b[1] - b[0];
         });
    int ans = 0, N = costs.size();
    for (int i = 0; i < N / 2; ++i) ans += costs[i][0] + costs[N - 1 - i][1];
    return ans;
  }
};
