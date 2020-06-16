// OJ:
// https://leetcode.com/problems/find-two-non-overlapping-sub-arrays-each-with-target-sum/
// Author: github.com/elaijuh
// Time: O(n)
// Space: O(n)
class Solution {
 public:
  int minSumOfLengths(vector<int>& arr, int target) {
    int n = arr.size();
    vector<int> min_lens(n, INT_MAX);  // min_lens[i] 0 i-1      subarray
    int l = 0, r = 0, min_len = INT_MAX, sum = 0;
    int ans = INT_MAX;
    for (int r = 0; r < n; ++r) {
      sum += arr[r];                         //
      while (sum > target) sum -= arr[l++];  //
      if (sum == target) {
        const int len = r - l + 1;
        if (l > 0 && min_lens[l - 1] != INT_MAX)
          ans = min(ans, min_lens[l - 1] + len);
        min_len = min(min_len, len);
      }
      min_lens[r] = min_len;
    }
    return ans == INT_MAX ? -1 : ans;
  }
};
