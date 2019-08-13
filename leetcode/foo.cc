#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool comp(vector<int> a, vector<int> b) { return a[0] < b[0]; }

int main() {
  vector<vector<int>> a = {{3, 2}, {1, 4}, {2, 8}};

  sort(a.begin(), a.end(), comp);

  for (auto x : a) {
    cout << "[";
    for (int y : x) cout << y << ",";
    cout << "]" << endl;
  }

  return 0;
}
