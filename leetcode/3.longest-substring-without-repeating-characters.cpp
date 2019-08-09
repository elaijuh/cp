/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// sliding window
class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> c;
    int i = 0, j = 0, m = 0;
    while (i < s.length() && j < s.length()) {
      auto it = c.find(s[i]);
      if (it != c.end()) {
        j = max(j, it->second);
      }
      m = max(m, i - j + 1);
      c[s[i]] = i + 1;
      i++;
    }
    return m;
  }
};
