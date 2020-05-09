/*
 * @lc app=leetcode id=1232 lang=cpp
 *
 * [1232] Check If It Is a Straight Line
 *
 * https://leetcode.com/problems/check-if-it-is-a-straight-line/description/
 *
 * algorithms
 * Easy (48.66%)
 * Likes:    242
 * Dislikes: 36
 * Total Accepted:    45.4K
 * Total Submissions: 93.2K
 * Testcase Example:  '[[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]'
 *
 * You are given an array coordinates, coordinates[i] = [x, y], where [x, y]
 * represents the coordinate of a point. Check if these points make a straight
 * line in the XY plane.
 *
 *
 *
 *
 * Example 1:
 *
 *
 *
 *
 * Input: coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
 * Output: true
 *
 *
 * Example 2:
 *
 *
 *
 *
 * Input: coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
 * Output: false
 *
 *
 *
 * Constraints:
 *
 *
 * 2 <= coordinates.length <= 1000
 * coordinates[i].length == 2
 * -10^4 <= coordinates[i][0], coordinates[i][1] <= 10^4
 * coordinates contains no duplicate point.
 *
 *
 */

// @lc code=start
class Solution {
 public:
  bool checkStraightLine(vector<vector<int>>& coordinates) {
    int n = coordinates.size();
    if (n == 2) return true;
    int x0 = coordinates[1][0] - coordinates[0][0];
    int y0 = coordinates[1][1] - coordinates[0][1];
    for (int i = 2; i < n; i++) {
      int xi = coordinates[i][0] - coordinates[i - 1][0];
      int yi = coordinates[i][1] - coordinates[i - 1][1];
      if (x0 * yi - xi * y0 != 0) return false;
    }
    return true;
  }
};
// @lc code=end
