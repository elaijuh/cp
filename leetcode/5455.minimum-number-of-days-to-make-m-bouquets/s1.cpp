// OJ: https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/
// Author: github.com/elaijuh
// Time: O(nlogn)
// Space: O()
class Solution {
 public:
  int getBouquets(vector<int>& A, int k, int d) {
    int ans = 0, cnt = 0;
    for (int i = 0; i < A.size(); ++i) {
      if (A[i] <= d) {
        cnt++;
        if (cnt == k) {
          cnt = 0;
          ans++;
        }
      } else
        cnt = 0;
    }
    return ans;
  }
  int minDays(vector<int>& bloomDay, int m, int k) {
    int l = *min_element(bloomDay.begin(), bloomDay.end());
    int r = *max_element(bloomDay.begin(), bloomDay.end());
    while (l < r) {
      int mi = (l + r) >> 1;
      int b = getBouquets(bloomDay, k, mi);
      if (b < m)
        l = mi + 1;
      else
        r = mi;
    }
    return getBouquets(bloomDay, k, l) >= m ? l : -1;
  }
};
