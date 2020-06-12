// OJ: https://leetcode.com/problems/insert-delete-getrandom-o1/
// Author: github.com/elaijuh
// Time: O()
// Space: O()
class RandomizedSet {
 public:
  unordered_map<int, int> m;
  vector<int> a;
  int n = 0;
  /** Initialize your data structure here. */
  RandomizedSet() {}
  /** Inserts a value to the set. Returns true if the set did not already
   * contain the specified element. */
  bool insert(int val) {
    if (m.find(val) != m.end()) return false;
    m[val] = n++;
    a.push_back(val);
    return true;
  }
  /** Removes a value from the set. Returns true if the set contained the
   * specified element. */
  bool remove(int val) {
    auto it = m.find(val);
    if (it == m.end()) return false;
    a[it->second] = a.back();
    m[a.back()] = it->second;
    a.pop_back();
    m.erase(val);
    n--;
    return true;
  }
  /** Get a random element from the set. */
  int getRandom() { return a[rand() % n]; }
};
/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
