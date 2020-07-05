// OJ:
// https://leetcode.com/problems/last-moment-before-all-ants-fall-out-of-a-plank/
// Author: github.com/elaijuh
// Time: O(n)
// Space: O()
class Solution {
 public:
  int getLastMoment(int n, vector<int>& left, vector<int>& right) {
    sort(left.begin(), left.end(), greater<int>());
    sort(right.begin(), right.end());
    // int nr=right.size(), nl=left.size();
    if (right.size() && left.size())
      return max(left[0], n - right[0]);
    else if (left.size())
      return left[0];
    else
      return n - right[0];
  }
};
