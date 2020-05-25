// OJ:
// https://leetcode.com/problems/form-largest-integer-with-digits-that-add-up-to-target/
// Author: github.com/elaijuh
// Time: O(target)
// Space: O(target)
class Solution {
 public:
  bool isGreaterThan(string& a, string& b) {
    return a.size() != b.size() ? a.size() > b.size() : a > b;
  }
  string largestNumber(vector<int>& cost, int target) {
    vector<vector<string>> dp(10, vector<string>(target + 1, "0"));
    for (int i = 0; i < 10; ++i) dp[i][0] = "";
    for (int i = 0; i < 9; ++i)
      for (int c = 1; c <= target; ++c) {
        dp[i + 1][c] = dp[i][c];
        if (c < cost[i] || dp[i + 1][c - cost[i]] == "0") continue;
        string s = string(1, '1' + i) + dp[i + 1][c - cost[i]];
        if (isGreaterThan(s, dp[i + 1][c])) dp[i + 1][c] = s;
      }
    return dp[9][target];
  }
};
static auto x = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return nullptr;
}();
