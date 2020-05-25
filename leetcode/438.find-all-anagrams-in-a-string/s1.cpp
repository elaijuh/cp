// OJ: https://leetcode.com/problems/find-all-anagrams-in-a-string/
// Author: github.com/elaijuh
// Time: O()
// Space: O()
class Solution {
 public:
  vector<int> findAnagrams(string s, string p) {
    int m[26] = {0};
    int l = 0;
    int r = 0;
    for (auto c : p) m[c - 'a']++;
    vector<int> ans;
    while (r < s.size()) {
      if (m[s[r] - 'a'] > 0) {
        m[s[r++] - 'a']--;
        if (r - l == p.size()) ans.push_back(l);
      } else if (l == r) {
        l++;
        r++;
      } else {
        m[s[l] - 'a']++;
        l++;
      }
    }
    return ans;
  }
};
