// OJ: https://leetcode.com/problems/is-subsequence/
// Author: github.com/elaijuh
// Time: O(N+M)
// Space: O()
class Solution {
 public:
  bool isSubsequence(string s, string t) {
    int m = s.size(), n = t.size();
    if (m > n) return false;
    int i = 0, j = 0;
    while (i < m && j < n) {
      if (s[i] == t[j]) i++;
      j++;
    }
    return i == m;
  }
};
