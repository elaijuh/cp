// OJ:
// https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/
// Author: github.com/elaijuh
// Time: O(N)
// Space: O()
class Solution {
 public:
  int maxProduct(vector<int>& nums) {
    sort(nums.begin(), nums.end(), greater<int>());
    return (nums[0] - 1) * (nums[1] - 1);
  }
};
