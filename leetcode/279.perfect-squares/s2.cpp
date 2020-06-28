// OJ: https://leetcode.com/problems/perfect-squares/
// Author: github.com/elaijuh
// Time: O(n)
// Space: O(n)
// https://en.wikipedia.org/wiki/Lagrange%27s_four-square_theorem
class Solution {
 public:
  int numSquares(int n) {
    vector<int> a;
    for (int i = 1; i * i <= n; ++i) a.push_back(i * i);

    // 1 sum
    if (count(a.begin(), a.end(), n)) return 1;

    // 2 sum
    unordered_set<int> s;
    for (int& x : a) {
      s.insert(x);
      int b = n - x;
      if (s.count(b)) return 2;
    }

    // 3 sum
    for (int& x : a) {
      int l = 0, h = a.size() - 1;
      while (l <= h) {
        int sum = a[l] + x + a[h];
        if (sum == n)
          return 3;
        else if (sum < n)
          l++;
        else
          h--;
      }
    }

    // Lagrange's four square theorem
    return 4;
  }
};
