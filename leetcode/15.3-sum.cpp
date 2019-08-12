/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// two pointers

class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    set<vector<int>> s;
    int n = nums.size();
    int l, r, sum;
    for (int i = 0; i < n; i++) {
      if (nums[i] > 0) continue;
      l = i + 1;
      r = n - 1;
      while (l < r) {
        sum = nums[i] + nums[l] + nums[r];
        if (sum == 0) {
          s.insert({nums[i], nums[l], nums[r]});
          l++;
          r--;
        } else if (sum < 0)
          l++;
        else
          r--;
      }
    }
    vector<vector<int>> ans(s.begin(), s.end());
    return ans;
  }
};
