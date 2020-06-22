// OJ: https://leetcode.com/problems/single-number-ii/
// Author: github.com/elaijuh
// Time: O(32n)
// Space: O()
class Solution {
 public:
  int singleNumber(vector<int>& nums) {
    int n = nums.size();
    long ans = 0;
    for (int i = 0; i < 32; ++i) {
      int t = 0;
      for (int j = 0; j < n; ++j) {
        t += nums[j] & 1;
        nums[j] >>= 1;
      }
      ans += (t % 3) * pow(2, i);
    }
    return ans;
  }
};
