// OJ: https://leetcode.com/problems/power-of-two/
// Author: github.com/elaijuh
// Time: O(1)
// Space: O()
class Solution {
 public:
  bool isPowerOfTwo(int n) {
    if (n <= 0) return false;
    return (n & (n - 1)) == 0;
  }
};
