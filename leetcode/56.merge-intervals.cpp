/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

class Solution {
  static bool comp(const vector<int> &a, const vector<int> &b) {
    return a[0] < b[0];
  }

 public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    sort(intervals.begin(), intervals.end(), comp);
    vector<vector<int>> ans;
    int n = intervals.size();
    if (n == 0) {
      return ans;
    }
    int l = intervals[0][0], r = intervals[0][1];
    for (int i = 1; i < n; i++) {
      if (intervals[i][0] <= r) {
        if (intervals[i][1] > r) {
          r = intervals[i][1];
        }
      } else {
        ans.push_back({l, r});
        l = intervals[i][0];
        r = intervals[i][1];
      }
    }
    ans.push_back({l, r});
    return ans;
  }
};
