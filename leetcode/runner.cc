#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
// #include "344_reverse_string.cc"

int main() {
  // Solution s;
  // vector<int> cost{4, 3, 2, 5, 6, 7, 2, 5, 5};
  // int target = 9;
  vector<string> a = {"abc", "efg", "zi"};
  vector<string> b = {
      "abc",
      "efd",
  };
  cout << includes(a.begin(), a.end(), b.begin(), b.end()) << endl;

  // auto ans = s.largestNumber(cost, target);
  // cout << ans << endl;

  return 0;
}
