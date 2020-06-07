// OJ: https://leetcode.com/problems/design-browser-history/
// Author: github.com/elaijuh
// Time: O()
// Space: O()
class BrowserHistory {
  vector<string> a;
  int p;

 public:
  BrowserHistory(string homepage) {
    a.push_back(homepage);
    p = 0;
  }
  void visit(string url) {
    a.resize(p + 1);
    a.push_back(url);
    p++;
  }
  string back(int steps) {
    p = p - steps;
    if (p < 0) p = 0;
    return a[p];
  }
  string forward(int steps) {
    p = p + steps;
    if (p > a.size() - 1) p = a.size() - 1;
    return a[p];
  }
};
/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
