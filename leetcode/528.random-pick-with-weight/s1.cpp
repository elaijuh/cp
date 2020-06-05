// OJ: https://leetcode.com/problems/random-pick-with-weight/
// Author: github.com/elaijuh
// Time: O(N+logN)
// Space: O(N)
class Solution {
 public:
  vector<int> p;
  Solution(vector<int>& w) {
    p.push_back(w[0]);
    p.resize(w.size());
    p[0] = w[0];
    for (int i = 1; i < w.size(); ++i) p[i] = p[i - 1] + w[i];
  }
  int pickIndex() {
    int n = rand() % p.back();
    return upper_bound(p.begin(), p.end(), n) - p.begin();
  }
};
/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
