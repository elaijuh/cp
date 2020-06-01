// OJ:
// https://leetcode.com/problems/make-two-arrays-equal-by-reversing-sub-arrays/
// Author: github.com/elaijuh
// Time: O(N)
// Space: O(N)
class Solution {
 public:
  bool canBeEqual(vector<int>& target, vector<int>& arr) {
    unordered_map<int, int> m;
    for (int x : target) m[x]++;
    for (int x : arr) {
      if (m.find(x) == m.end())
        return false;
      else
        m[x]--;
    }
    for (auto x : m)
      if (x.second != 0) return false;
    return true;
  }
};
