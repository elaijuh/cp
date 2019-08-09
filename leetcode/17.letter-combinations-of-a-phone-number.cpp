/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

// backtracking

class Solution {
  vector<string> ans;

  string getLettersByDigit(char c) {
    string s;
    switch (c) {
      case '2':
        s = "abc";
        break;
      case '3':
        s = "def";
        break;
      case '4':
        s = "ghi";
        break;
      case '5':
        s = "jkl";
        break;
      case '6':
        s = "mno";
        break;
      case '7':
        s = "pqrs";
        break;
      case '8':
        s = "tuv";
        break;
      case '9':
        s = "wxyz";
        break;
    }
    return s;
  }

  void comb(string digits, string s, int index, int r) {
    if (index == r) {
      if (r != 0) {
        ans.push_back(s);
      }
      return;
    }
    string ss = getLettersByDigit(digits[index]);
    for (char c : ss) {
      s.replace(index, 1, 1, c);
      comb(digits, s, index + 1, r);
    }
  }

 public:
  vector<string> letterCombinations(string digits) {
    comb(digits, "", 0, digits.length());
    return ans;
  }
};
