/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */

// binary search
// a1,a2,...,am1-1,am1,...,an1
// b1,b2,...,bm2-1,bm2,...,bn2
// criteria: median must be in [am1-1, am1, bm2-1, bm2]; m1+m2=(n1+n2+1)/2;
// a[m1]>b[m2-1]

// reference:
// https://www.youtube.com/watch?v=KB9IcSCDQ9k

class Solution {
 public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n1 = nums1.size();
    int n2 = nums2.size();
    if (n1 > n2) return findMedianSortedArrays(nums2, nums1);
    // if n1+n2 is odd, kth element is median
    // if n1+n2 is even, kth element is right median, k-1th element is left
    int k = (n1 + n2 + 1) / 2;
    int l = 0, r = n1;
    while (l < r) {
      int m1 = (l + r) / 2;
      int m2 = k - m1;
      if (nums1[m1] < nums2[m2 - 1])
        // make m1 bigger
        l = m1 + 1;
      else
        // make m1 smaller
        r = m1;
    }
    int m1 = l;
    int m2 = k - l;
    int c1 = max(m1 <= 0 ? INT_MIN : nums1[m1 - 1],
                 m2 <= 0 ? INT_MIN : nums2[m2 - 1]);
    if ((n1 + n2) % 2 == 1) return c1;
    int c2 =
        min(m1 >= n1 ? INT_MAX : nums1[m1], m2 >= n2 ? INT_MAX : nums2[m2]);
    return (c1 + c2) * 0.5;
  }
};
