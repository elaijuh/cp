// OJ:
// https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/
// Author: github.com/elaijuh
// Time: O(NlogN)
// Space: O()
class Solution {
 public:
  int maxArea(int h, int w, vector<int>& horizontalCuts,
              vector<int>& verticalCuts) {
    int maxh = 0, maxw = 0;
    sort(horizontalCuts.begin(), horizontalCuts.end());
    sort(verticalCuts.begin(), verticalCuts.end());
    for (int i = 0; i < horizontalCuts.size() - 1; ++i)
      maxh = max(maxh, horizontalCuts[i + 1] - horizontalCuts[i]);
    maxh = max(maxh, horizontalCuts[0] - 0);
    maxh = max(maxh, h - horizontalCuts[horizontalCuts.size() - 1]);
    for (int i = 0; i < verticalCuts.size() - 1; ++i)
      maxw = max(maxw, verticalCuts[i + 1] - verticalCuts[i]);
    maxw = max(maxw, verticalCuts[0] - 0);
    maxw = max(maxw, w - verticalCuts[verticalCuts.size() - 1]);
    unsigned int M = 1000000007;
    // unsigned long long ans = (unsigned long long)maxh * (unsigned long
    // long)maxw;
    unsigned long long ans =
        (unsigned long long)maxh % M * (unsigned long long)maxw % M;
    return (int)ans % M;
  }
};
