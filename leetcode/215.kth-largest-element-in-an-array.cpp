/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 */

// @lc code=start
class Solution {
  int partition(vector<int>& a, int l, int h) {
    // avoid worst case, it takes 88ms w/o this statement
    swap(a[l], a[rand() % (h - l + 1) + l]);
    int p = h;
    int fh = l;
    for (int i = l; i < h; i++) {
      if (a[i] < a[p]) {
        swap(a[i], a[fh]);
        fh++;
      }
    }
    swap(a[p], a[fh]);
    return fh;
  }

 public:
  int findKthLargest(vector<int>& nums, int k) {
    int n = nums.size();
    int l = 0;
    int h = n - 1;
    int p = 0;
    while (l <= h) {
      p = partition(nums, l, h);
      if (k < n - p) {
        l = p + 1;
      } else if (k > n - p) {
        h = p - 1;
      } else {
        break;
      }
    }
    return nums[p];
  }
};
// @lc code=end
