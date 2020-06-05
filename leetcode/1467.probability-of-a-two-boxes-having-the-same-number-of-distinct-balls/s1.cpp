// OJ:
// https://leetcode.com/problems/probability-of-a-two-boxes-having-the-same-number-of-distinct-balls/
// Author: github.com/elaijuh
// Time: O(N!)
// Space: O()
class Solution {
 public:
  int sum = 0;
  double factorial(int x) { return x == 0 ? 1 : x * factorial(x - 1); }
  double perm(vector<int>& A) {
    int sum = accumulate(A.begin(), A.end(), 0);
    double p = factorial(sum);
    double d = 1;
    for (int i = 0; i < A.size(); ++i) d *= factorial(A[i]);
    return p / d;
  }
  double dfs(vector<int>& A, vector<int>& a, vector<int>& b, int col, int cnta,
             int cntb) {
    if (cnta > sum / 2 || cntb > sum / 2) return 0;
    if (col == A.size()) {  // finish dfs
      int cola = 0, colb = 0;
      for (auto x : a) cola += x > 0;
      for (auto x : b) colb += x > 0;
      if (cola != colb) return 0;
      return perm(a) * perm(b);
    }
    double ans = 0;
    for (int i = 0; i <= A[col]; ++i) {
      a[col] = i;
      b[col] = A[col] - i;
      ans += dfs(A, a, b, col + 1, cnta + a[col], cntb + b[col]);
    }
    return ans;
  }
  double getProbability(vector<int>& balls) {
    sum = accumulate(balls.begin(), balls.end(), 0);
    vector<int> a(balls.size()), b(balls.size());
    return dfs(balls, a, b, 0, 0, 0) / perm(balls);
  }
};
