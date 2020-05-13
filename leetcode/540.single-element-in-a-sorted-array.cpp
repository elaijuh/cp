/*
 * @lc app=leetcode id=540 lang=cpp
 *
 * [540] Single Element in a Sorted Array
 *
 * https://leetcode.com/problems/single-element-in-a-sorted-array/description/
 *
 * algorithms
 * Medium (57.68%)
 * Likes:    1297
 * Dislikes: 76
 * Total Accepted:    106.8K
 * Total Submissions: 183.3K
 * Testcase Example:  '[1,1,2,3,3,4,4,8,8]'
 *
 * You are given a sorted array consisting of only integers where every element
 * appears exactly twice, except for one element which appears exactly once.
 * Find this single element that appears only once.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: [1,1,2,3,3,4,4,8,8]
 * Output: 2
 *
 *
 * Example 2:
 *
 *
 * Input: [3,3,7,7,10,11,11]
 * Output: 10
 *
 *
 *
 *
 * Note: Your solution should run in O(log n) time and O(1) space.
 *
 */

// @lc code=start
class Solution {
 public:
  int singleNonDuplicate(vector<int>& nums) {
    int l = 0;
    int r = nums.size() - 1;
    while (l < r) {
      int p = (l + r) >> 1;
      if ((p % 2 == 1 && nums[p] == nums[p - 1]) ||
          (p % 2 == 0 && nums[p] == nums[p + 1]))
        l = p + 1;
      else
        r = p;
    }
    return nums[l];
  }
};
// @lc code=end
