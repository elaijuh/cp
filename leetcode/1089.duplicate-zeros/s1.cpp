// OJ: https://leetcode.com/problems/duplicate-zeros/
// Author: github.com/elaijuh
// Time: O(N)
// Space: O()
class Solution {
 public:
  void duplicateZeros(vector<int>& arr) {
    int r = arr.size() - 1, l = 0;
    while (l < r)
      if (arr[l++] == 0) r--;
    int dup = arr.size() - 1 - r;
    if (l == r && arr[r] == 0) {  // edge case: last element is 0;
      arr[r + dup] = arr[r];
      r--;
    }
    while (r >= 0) {
      if (arr[r] != 0)
        arr[r + dup] = arr[r];
      else {
        arr[r + dup--] = arr[r];
        arr[r + dup] = arr[r];
      }
      r--;
    }
  }
};
