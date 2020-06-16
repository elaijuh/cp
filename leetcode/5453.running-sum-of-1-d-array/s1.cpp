// OJ: https://leetcode.com/problems/running-sum-of-1d-array/
// Author: github.com/elaijuh
// Time: O(n)
// Space: O()
class Solution {
 public:
  vector<int> runningSum(vector<int>& nums) {
    for (int i = 1; i < nums.size(); ++i) nums[i] += nums[i - 1];
    return nums;
  }
};
