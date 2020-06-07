// OJ: https://leetcode.com/problems/the-k-strongest-values-in-an-array/
// Author: github.com/elaijuh
// Time: O(NlogN)
// Space: O()
class Solution {
 public:
  vector<int> getStrongest(vector<int>& arr, int k) {
    sort(arr.begin(), arr.end());
    int m = arr[(arr.size() - 1) / 2];
    sort(arr.begin(), arr.end(), [&](const int& a, const int& b) {
      return abs(a - m) > abs(b - m) || abs(a - m) == abs(b - m) && a > b;
    });
    arr.resize(k);
    return arr;
  }
};
