/*
 * @lc app=leetcode id=367 lang=cpp
 *
 * [367] Valid Perfect Square
 *
 * https://leetcode.com/problems/valid-perfect-square/description/
 *
 * algorithms
 * Easy (41.06%)
 * Likes:    720
 * Dislikes: 154
 * Total Accepted:    177.7K
 * Total Submissions: 430K
 * Testcase Example:  '16'
 *
 * Given a positive integer num, write a function which returns True if num is
 * a perfect square else False.
 *
 * Note: Do not use any built-in library function such as sqrt.
 *
 * Example 1:
 *
 *
 *
 * Input: 16
 * Output: true
 *
 *
 *
 * Example 2:
 *
 *
 * Input: 14
 * Output: false
 *
 *
 *
 */

// @lc code=start
class Solution {
 public:
  bool isPerfectSquare(int num) {
    int i = -1;
    while ((num -= (i += 2)) > 0)
      ;
    return num == 0 ? true : false;
  }
};
// @lc code=end
