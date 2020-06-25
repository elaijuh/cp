// OJ: https://leetcode.com/problems/find-the-duplicate-number/
// Author: github.com/elaijuh
// Time: O(n)
// Space: O(1)
class Solution {
 public:
  int findDuplicate(vector<int>& nums) {
    int slow = nums[0], fast = nums[nums[0]];
    //
    while (slow != fast) {
      slow = nums[slow];
      fast = nums[nums[fast]];
    }
    printf("%d\n", slow);
    //
    slow = 0;
    while (slow != fast) {
      slow = nums[slow];
      fast = nums[fast];
    }
    return slow;
  }
};
