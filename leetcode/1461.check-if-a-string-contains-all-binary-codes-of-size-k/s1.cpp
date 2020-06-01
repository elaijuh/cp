// OJ:
// https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/
// Author: github.com/elaijuh
// Time: O(N)
// Space: O(2^k)
class Solution {
 public:
  bool hasAllCodes(string s, int k) {
    int n = s.size();
    if (n < k) return false;
    unordered_set<string> set;
    for (int i = 0; i < n - k + 1; ++i) set.insert(s.substr(i, k));
    if (set.size() != pow(2, k)) return false;
    return true;
  }
};
