/*
 * @lc app=leetcode id=402 lang=cpp
 *
 * [402] Remove K Digits
 *
 * https://leetcode.com/problems/remove-k-digits/description/
 *
 * algorithms
 * Medium (27.66%)
 * Likes:    1746
 * Dislikes: 89
 * Total Accepted:    106K
 * Total Submissions: 381.9K
 * Testcase Example:  '"1432219"\n3'
 *
 * Given a non-negative integer num represented as a string, remove k digits
 * from the number so that the new number is the smallest possible.
 *
 *
 * Note:
 *
 * The length of num is less than 10002 and will be ≥ k.
 * The given num does not contain any leading zero.
 *
 *
 *
 *
 * Example 1:
 *
 * Input: num = "1432219", k = 3
 * Output: "1219"
 * Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219
 * which is the smallest.
 *
 *
 *
 * Example 2:
 *
 * Input: num = "10200", k = 1
 * Output: "200"
 * Explanation: Remove the leading 1 and the number is 200. Note that the
 * output must not contain leading zeroes.
 *
 *
 *
 * Example 3:
 *
 * Input: num = "10", k = 2
 * Output: "0"
 * Explanation: Remove all the digits from the number and it is left with
 * nothing which is 0.
 *
 *
 */

// @lc code=start
class Solution {
 public:
  string removeKdigits(string num, int k) {
    string ans = "";
    for (auto c : num) {
      while (ans.length() && ans.back() > c && k) {
        ans.pop_back();
        k--;
      }
      if (ans.length() || c != '0') {
        ans += c;
      }
    }
    while (k-- && ans.length()) ans.pop_back();

    return ans.length() ? ans : "0";
  }
};

static auto fastio = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();
// 贪心，每一次都设法去掉最高位较大的。算法满足单调性，正确性。
// @lc code=end
