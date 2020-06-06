// OJ: https://leetcode.com/problems/queue-reconstruction-by-height/
// Author: github.com/elaijuh
// Time: O()
// Space: O()
class Solution {
 public:
  vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    vector<vector<int>> ans(people.size(), vector<int>(2, INT_MAX));
    sort(people.begin(), people.end());
    for (int i = 0; i < people.size(); ++i) {
      int k = 0;
      for (int j = 0; j < people[i][1]; j++) {
        if (ans[k++][0] < people[i][0]) j--;
      }
      while (ans[k][0] < people[i][0]) k++;
      ans[k] = people[i];
    }
    return ans;
  }
};
