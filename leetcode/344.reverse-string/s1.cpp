// OJ: https://leetcode.com/problems/reverse-string/
// Author: github.com/elaijuh
// Time: O()
// Space: O()
class Solution {
 public:
  void reverseString(vector<char>& s) {
    int l = 0, r = s.size() - 1;
    while (l < r) swap(s[l++], s[r--]);
  }
};
