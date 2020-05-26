// OJ: https://leetcode.com/problems/contiguous-array/
// Author: github.com/elaijuh
// Time: O(N)
// Space: O(N)
class Solution {
 public:
  int findMaxLength(vector<int>& nums) {
    int N = nums.size();
    unordered_map<int, int> m;
    m[0] = -1;
    int cur = 0, ans = 0;
    for (int i = 0; i < N; ++i) {
      cur += nums[i] == 0 ? 1 : -1;
      if (m.find(cur) == m.end())
        m[cur] = i;
      else
        ans = max(ans, i - m[cur]);
    }
    return ans;
  }
};
