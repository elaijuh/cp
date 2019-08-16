#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  string a = "abcde";
  size_t i = a.find_first_of('b');
  cout << a.substr(0) << endl;

  return 0;
}
