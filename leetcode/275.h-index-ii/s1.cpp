// OJ: https://leetcode.com/problems/h-index-ii/
// Author: github.com/elaijuh
// Time: O(logn)
// Space: O()
class Solution {
 public:
  int hIndex(vector<int>& c) {
    int n = c.size();
    if (!n) return 0;
    int low = 0, high = n - 1;
    int ans = 0;
    while (low <= high) {
      int mid = low + (high - low) / 2;
      if (c[mid] >= n - mid) {
        ans = n - mid;
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }
    return ans;
  }
};
