#include <algorithm>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<string> split(const string& s, const char delim = ' ') {
    stringstream ss(s);
    string token;
    vector<string> cont;
    while (getline(ss, token, delim)) {
      cont.push_back(token);
    }
    return cont;
  }

  vector<string> invalidTransactions(vector<string>& transactions) {
    int n = transactions.size();
    unordered_set<string> s;
    unordered_map<string, vector<string>> m;
    for (int i = 0; i < n; i++) {
      vector<string> t1 = split(transactions[i], ',');
      if (stoi(t1[2]) > 1000) {
        s.insert(transactions[i]);
      }
      vector<string>& a = m[t1[0]];
      if (a.size() != 0) {
        for (int j = 0; j < a.size(); j++) {
          vector<string> t2 = split(a[j], ',');
          if (t1[0] == t2[0] && t1[3] != t2[3] &&
              (stoi(t1[1]) - stoi(t2[1]) <= 60) &&
              (stoi(t1[1]) - stoi(t2[1]) >= -60)) {
            s.insert(transactions[i]);
            s.insert(a[j]);
          }
        }
      }
      a.push_back(transactions[i]);
    }
    vector<string> ans(s.begin(), s.end());
    return ans;
  }
};

int main() {
  Solution solution;
  vector<string> input = {
      "bob,689,1910,barcelona",      "alex,696,122,bangkok",
      "bob,832,1726,barcelona",      "bob,820,596,bangkok",
      "chalicefy,217,669,barcelona", "bob,175,221,amsterdam"};
  vector<string> ans = solution.invalidTransactions(input);
  for (auto& x : ans) cout << x << endl;
  return 0;
}
