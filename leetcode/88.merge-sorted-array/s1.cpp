// OJ: https://leetcode.com/problems/merge-sorted-array/
// Author: github.com/elaijuh
// Time: O(m+n)
// Space: O()
class Solution {
 public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    nums1.resize(m + n);
    int i = m - 1, j = n - 1, k = m + n - 1;
    while (i >= 0 && j >= 0) {
      if (nums1[i] > nums2[j]) {
        nums1[k--] = nums1[i--];
      } else {
        nums1[k--] = nums2[j--];
      }
    }
    while (i >= 0) {
      nums1[k--] = nums1[i--];
    }
    while (j >= 0) {
      nums1[k--] = nums2[j--];
    }
  }
};
