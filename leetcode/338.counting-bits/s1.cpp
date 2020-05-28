// OJ: https://leetcode.com/problems/counting-bits/
// Author: github.com/elaijuh
// Time: O(N)
// Space: O(N)
class Solution {
 public:
  vector<int> countBits(int num) {
    vector<int> ans(num + 1);
    ans[0] = 0;
    if (num == 0)
      return ans;
    else
      ans[1] = 1;
    if (num < 2) return ans;
    int s = 2, j = 2;
    while (true) {
      int k = s / 2;
      while (k--) {
        if (j > num) return ans;
        ans[j] = ans[j - s / 2];
        j++;
      }
      k = s / 2;
      while (k--) {
        if (j > num) return ans;
        ans[j] = ans[j - s / 2] + 1;
        j++;
      }
      s *= 2;
    }
    return ans;
  }
};
