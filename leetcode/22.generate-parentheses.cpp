/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */
class Solution {
  vector<string> ans;

  bool validate(string s) {
    stack<char> a;
    for (char c : s) {
      if (c == ')') {
        if (a.size() == 0)
          return false;
        else
          a.pop();
      } else {
        a.push(c);
      }
    }
    return true;
  }

  void permute(string s, int l, int r) {
    if (l == r) {
      if (validate(s)) ans.push_back(s);
      return;
    }
    for (int k = l; k <= r; k++) {
      if (s[l] != s[k]) {
        swap(s[l], s[k]);
        permute(s, l + 1, r);
        swap(s[l], s[k]);
      }
    }
  }

 public:
  vector<string> generateParenthesis(int n) {
    string s(n, '(');
    s.insert(s.end(), n, ')');
    permute(s, 0, 2 * n - 1);
    return ans;
  }
};
