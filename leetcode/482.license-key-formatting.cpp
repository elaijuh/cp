/*
 * @lc app=leetcode id=482 lang=cpp
 *
 * [482] License Key Formatting
 */
class Solution {
 public:
  string licenseKeyFormatting(string S, int K) {
    int n = S.length() - 1;
    string s = "";
    while (n >= 0) {
      for (int i = 0; i < K && n >= 0; i++) {
        if (S[n] == '-')
          i--;
        else
          s += toupper(S[n]);
        n--;
      }
      if (n >= 0) s += '-';
    }
    if (s.back() == '-') {
      s.erase(s.length() - 1, 1);
    }
    reverse(s.begin(), s.end());
    return s;
  }
};
