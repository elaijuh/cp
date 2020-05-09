/*
 * @lc app=leetcode id=977 lang=cpp
 *
 * [977] Squares of a Sorted Array
 *
 * https://leetcode.com/problems/squares-of-a-sorted-array/description/
 *
 * algorithms
 * Easy (72.40%)
 * Likes:    938
 * Dislikes: 78
 * Total Accepted:    192.8K
 * Total Submissions: 266.4K
 * Testcase Example:  '[-4,-1,0,3,10]'
 *
 * Given an array of integers A sorted in non-decreasing order, return an array
 * of the squares of each number, also in sorted non-decreasing order.
 *
 *
 *
 *
 * Example 1:
 *
 *
 * Input: [-4,-1,0,3,10]
 * Output: [0,1,9,16,100]
 *
 *
 *
 * Example 2:
 *
 *
 * Input: [-7,-3,2,3,11]
 * Output: [4,9,9,49,121]
 *
 *
 *
 *
 * Note:
 *
 *
 * 1 <= A.length <= 10000
 * -10000 <= A[i] <= 10000
 * A is sorted in non-decreasing order.
 *
 *
 *
 */

// @lc code=start
/**
 * method 1: sort array first
class Solution {
public:
    static bool comp(int a, int b) {
        return abs(a)<abs(b);
    }

    vector<int> sortedSquares(vector<int>& A) {
        sort(A.begin(), A.end(), comp);
        for (int i=0;i<A.size();i++) A[i]*=A[i];
        return A;

    }
};
*/

/**
 * method 2: create a new vector with 2 pointers
 */
class Solution {
 public:
  vector<int> sortedSquares(vector<int>& A) {
    int n = A.size();
    vector<int> ans(n);
    int l = 0;
    int r = n - 1;

    for (int i = 0; i < n; i++)
      if (A[i] < 0) A[i] = -A[i];
    while (l <= r) {
      if (A[r] > A[l])
        ans[--n] = A[r] * A[r--];
      else
        ans[--n] = A[l] * A[l++];
    }
    return ans;
  }
};
// @lc code=end
