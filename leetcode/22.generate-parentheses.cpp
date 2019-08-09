/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

// backtracking

class Solution {
  vector<string> ans;
  stack<char> tmpstack;

  void backtrack(string s, int open, int close, int n) {
    if (s.length() == 2 * n) {
      ans.push_back(s);
      return;
    }
    if (open < n) {
      tmpstack.push('(');
      backtrack(s + '(', open + 1, close, n);
      tmpstack.pop();
    }
    if (close < n && !tmpstack.empty()) {
      tmpstack.pop();
      backtrack(s + ')', open, close + 1, n);
      tmpstack.push('(');
    }
  }

 public:
  vector<string> generateParenthesis(int n) {
    backtrack("", 0, 0, n);
    return ans;
  }
};
