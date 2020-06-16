// OJ:
// https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/
// Author: github.com/elaijuh
// Time: O(nlogn)
// Space: O()
class Solution {
 public:
  int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
    unordered_map<int, int> m;
    for (auto x : arr) m[x]++;
    vector<int> count;
    for (auto x : m) count.push_back(x.second);
    sort(count.begin(), count.end());
    int n = count.size();
    for (int i = 0; i < n; ++i) {
      if (k >= count[i])
        k -= count[i];
      else
        return n - i;
    }
    return 0;
  }
};
