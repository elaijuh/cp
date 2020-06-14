// OJ: https://leetcode.com/problems/cheapest-flights-within-k-stops/
// Author: github.com/elaijuh
// Time: O(V+E)
// Space: O()
// DFS
class Solution {
 public:
  int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                        int K) {
    unordered_map<int, vector<vector<int>>> al;
    for (auto& f : flights) al[f[0]].push_back({f[1], f[2]});
    dfs(al, src, dst, K + 1, 0);
    return ans == INT_MAX ? -1 : ans;
  }

  void dfs(unordered_map<int, vector<vector<int>>>& al, int src, int dst, int k,
           int cost) {
    if (k < 0) return;
    if (src == dst) {
      ans = min(ans, cost);
      return;
    }
    if (al.find(src) == al.end()) return;
    for (auto& x : al[src]) {
      if (cost + x[1] > ans) continue;
      dfs(al, x[0], dst, k - 1, cost + x[1]);
    }
  }
};
