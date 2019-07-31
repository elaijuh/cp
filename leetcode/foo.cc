#include <algorithm>
#include <iostream>
#include <list>
#include <vector>

using namespace std;

int main() {
  list<int> a = {1, 2, 3, 4, 5, 11, 7};
  list<int>::iterator it;
  it = a.begin();
  a.insert(++it, 10);
  auto p = find(a.begin(), a.end(), 7);
  cout << (p == a.end()) << endl;

  return 0;
}
