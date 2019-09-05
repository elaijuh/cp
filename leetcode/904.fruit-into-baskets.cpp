/*
 * @lc app=leetcode id=904 lang=cpp
 *
 * [904] Fruit Into Baskets
 */

// tag: 2 pointers

class Solution {
 public:
  int totalFruit(vector<int>& tree) {
    int m = 0, k = 0, n = tree.size();
    int t1 = tree[0], t2 = -1;
    int l = 0, r = 0;
    while (r < n) {
      if (tree[r] == t1) {
        r++;
      } else if (tree[r] == t2 || t2 == -1) {
        t2 = tree[r];
        r++;
      } else {
        m = max(m, r - l);
        t1 = tree[r - 1];
        t2 = tree[r];
        for (int i = r - 1; i >= 0; i--) {
          if (tree[i] != t1) {
            l = i + 1;
            break;
          }
        }
      }
    }
    return max(m, r - l);
  }

  // solution: 36ms
  //   int totalFruit(vector<int>& tree) {
  //     int currentTotal = 0, type1 = -1, type2 = -1, count_type2 = 0, ans = 0;

  //     for (int currentFruit : tree) {
  //       currentTotal = (currentFruit == type1 || currentFruit == type2)
  //                          ? currentTotal + 1
  //                          : count_type2 + 1;
  //       if (currentFruit == type2)
  //         count_type2 += 1;
  //       else {
  //         count_type2 = 1;
  //         type1 = type2;
  //         type2 = currentFruit;
  //       }
  //       ans = max(ans, currentTotal);
  //     }
  //     return ans;
  //   }
};
