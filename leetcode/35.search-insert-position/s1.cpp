// OJ: https://leetcode.com/problems/search-insert-position/
// Author: github.com/elaijuh
// Time: O(logn)
// Space: O()
class Solution {
 public:
  int searchInsert(vector<int>& nums, int target) {
    int l = 0;
    int r = nums.size();
    int m;
    while (l < r) {
      m = (l + r) >> 1;
      if (nums[m] == target) return m;
      if (target < nums[m])
        r = m;
      else
        l = m + 1;
    }
    return l;
  }
};
