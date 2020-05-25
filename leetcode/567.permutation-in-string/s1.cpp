// OJ: https://leetcode.com/problems/permutation-in-string/
// Author: github.com/elaijuh
// Time: O()
// Space: O()
class Solution {
 public:
  bool checkInclusion(string s1, string s2) {
    int h[26] = {0};
    for (auto c : s1) h[c - 'a']++;
    int l = 0;
    int r = 0;
    while (r < s2.size()) {
      if (h[s2[r] - 'a'] > 0) {
        h[s2[r++] - 'a']--;
        if (r - l == s1.length()) return true;
      } else if (l == r) {
        l++;
        r++;
      } else {
        h[s2[l] - 'a']++;
        l++;
      }
    }
    return false;
  }
};
