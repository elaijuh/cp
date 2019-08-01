#include <algorithm>
#include <iostream>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> c;
    int j = 0;
    int max = 0;
    for (int i = 0; i < s.length(); i++) {
      auto x = c.find(s[i]);
      if (x == c.end()) {
        c.insert({s[i], i});
        if (c.size() > max) {
          max = c.size();
        }
      } else {
        int xv = x->second;
        for (int k = j; k <= xv; k++) c.erase(s[k]);
        j = xv + 1;
        i--;
      }
    }
    return max;
  }
};

int main() {
  Solution so = Solution();
  cout << so.lengthOfLongestSubstring("abcabcbb") << endl;

  return 0;
}
