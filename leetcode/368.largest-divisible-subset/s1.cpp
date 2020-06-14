// OJ: https://leetcode.com/problems/largest-divisible-subset/
// Author: github.com/elaijuh
// Time: O(n^2)
// Space: O()
class Solution {
 public:
  vector<int> largestDivisibleSubset(vector<int>& nums) {
    int n = nums.size();
    if (n <= 1) return nums;
    sort(nums.begin(), nums.end());
    vector<int> dp(n, 1);    // dp[i]: i
    vector<int> pre(n, -1);  // pre[i]: i          index
    int longest = INT_MIN;
    int pos = 0;  //             nums  index
    for (int i = 1; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        if (nums[i] % nums[j] == 0) dp[i] = max(dp[i], dp[j] + 1);
        if (dp[i] == dp[j] + 1) pre[i] = j;
      }
      if (longest < dp[i]) {
        longest = dp[i];
        pos = i;
      }
    }
    vector<int> ans(longest);
    printf("%d\n", dp[n - 1]);
    for (int i = longest - 1; i >= 0; --i) {
      ans[i] = nums[pos];
      pos = pre[pos];
    }
    return ans;
  }
};
