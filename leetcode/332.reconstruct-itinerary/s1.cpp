// OJ: https://leetcode.com/problems/reconstruct-itinerary/
// Author: github.com/elaijuh
// Time: O(e*loge)
// Space: O(e)
class Solution {
 public:
  vector<string> findItinerary(vector<vector<string>>& tickets) {
    unordered_map<string, vector<string>> m;
    for (auto x : tickets) m[x[0]].push_back(x[1]);
    for (auto& x : m)
      sort(x.second.begin(), x.second.end(),
           greater<string>());  //    vector.pop_back
    vector<string> ans;
    dfs(m, "JFK", ans);
    reverse(ans.begin(), ans.end());
    return ans;
  }
  void dfs(unordered_map<string, vector<string>>& m, string s,
           vector<string>& ans) {
    while (!m[s].empty()) {
      string ss = m[s].back();
      m[s].pop_back();
      dfs(m, ss, ans);
    }
    ans.push_back(s);
  }
};
