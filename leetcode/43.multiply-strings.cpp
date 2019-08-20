/*
 * @lc app=leetcode id=43 lang=cpp
 *
 * [43] Multiply Strings
 */
class Solution {
  string addString(string s1, string s2, int delta) {
    int l1 = s1.length(), l2 = s2.length();
    int l;
    if (l2 - l1 + delta > 0) s1.insert(s1.begin(), l2 - l1 + delta, '0');
    s2.insert(s2.end(), delta, '0');
    l = max(s1.length(), s2.length());
    int k = 0;
    string s = "";
    for (int i = l - 1; i >= 0; i--) {
      int m = s1[i] - '0' + s2[i] - '0' + k;
      k = m / 10;
      m %= 10;
      s.insert(0, 1, m + '0');
    }
    if (k == 1) s.insert(0, 1, k + '0');
    return s;
  }

 public:
  string multiply(string num1, string num2) {
    if (num1 == "0" || num2 == "0") return "0";
    int n1 = num1.length(), n2 = num2.length();
    int k;
    string s, s1;
    s = "";
    for (int i = n1 - 1; i >= 0; i--) {
      s1 = "";
      k = 0;
      for (int j = n2 - 1; j >= 0; j--) {
        int m = (num1[i] - '0') * (num2[j] - '0') + k;
        k = m / 10;
        m %= 10;
        s1.insert(0, 1, m + '0');
      }
      if (k > 0) s1.insert(0, 1, k + '0');
      s = addString(s, s1, n1 - 1 - i);
    }
    return s;
  }
};
