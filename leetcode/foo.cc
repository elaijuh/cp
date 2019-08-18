#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> a = {2, 3, 4, 1, 5};
  sort(a.begin() + 2, a.begin() + 4);
  for (auto x : a) cout << x;
  cout << endl;

  return 0;
}
