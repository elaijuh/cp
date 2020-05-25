// OJ: https://leetcode.com/problems/online-stock-span/
// Author: github.com/elaijuh
// Time: O()
// Space: O()
struct Node {
  int price;
  int count;
  Node* pred;
  Node(int x) : price(x), count(1), pred(nullptr) {}
};
class StockSpanner {
 public:
  Node* p;
  StockSpanner() { p = nullptr; }
  int next(int price) {
    Node* n = new Node(price);
    while (p && price >= p->price) {
      n->count += p->count;
      p = p->pred;
    }
    n->pred = p;
    p = n;
    return p->count;
  }
};
static auto x = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return nullptr;
}();
/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
