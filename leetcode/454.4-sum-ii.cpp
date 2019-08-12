/*
 * @lc app=leetcode id=454 lang=cpp
 *
 * [454] 4Sum II
 */
class Solution {
 public:
  int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C,
                   vector<int>& D) {
    unordered_map<int, int> m;
    for (int a : A)
      for (int b : B) m[a + b]++;

    int ans = 0;
    for (int c : C)
      for (int d : D)
        if (m.find((c + d) * -1) != m.end()) ans += m[(c + d) * -1];

    return ans;
  }
};
