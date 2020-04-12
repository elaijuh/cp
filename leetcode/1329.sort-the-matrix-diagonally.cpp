/*
 * @lc app=leetcode id=1329 lang=cpp
 *
 * [1329] Sort the Matrix Diagonally
 *
 * https://leetcode.com/problems/sort-the-matrix-diagonally/description/
 *
 * algorithms
 * Medium (77.77%)
 * Likes:    143
 * Dislikes: 56
 * Total Accepted:    8.8K
 * Total Submissions: 11.4K
 * Testcase Example:  '[[3,3,1,1],[2,2,1,2],[1,1,1,2]]'
 *
 * Given a m * n matrix mat of integers, sort it diagonally in ascending order
 * from the top-left to the bottom-right then return the sorted array.
 *
 *
 * Example 1:
 *
 *
 * Input: mat = [[3,3,1,1],[2,2,1,2],[1,1,1,2]]
 * Output: [[1,1,1,1],[1,2,2,2],[1,2,3,3]]
 *
 *
 *
 * Constraints:
 *
 *
 * m == mat.length
 * n == mat[i].length
 * 1 <= m, n <= 100
 * 1 <= mat[i][j] <= 100
 *
 */

// @lc code=start
#include <cstdlib>

#define MAX 100

class Solution {
 public:
  static int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
  }
  vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
    int m = mat.size(), n = mat[0].size();
    int k;
    int v[MAX];

    for (int j = 0; j < n; j++) {
      k = 0;
      for (int i = 0, jj = j; i < m && jj < n;) v[k++] = mat[i++][jj++];
      qsort(v, k, sizeof(int), compare);
      k = 0;
      for (int i = 0, jj = j; i < m && jj < n;) mat[i++][jj++] = v[k++];
    }
    for (int i = 1; i < m; i++) {
      k = 0;
      for (int ii = i, j = 0; ii < m && j < n;) v[k++] = mat[ii++][j++];
      qsort(v, k, sizeof(int), compare);
      k = 0;
      for (int ii = i, j = 0; ii < m && j < n;) mat[ii++][j++] = v[k++];
    }
    return mat;
  }
};
// @lc code=end
