/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 *
 * https://leetcode.com/problems/implement-trie-prefix-tree/description/
 *
 * algorithms
 * Medium (45.26%)
 * Likes:    2747
 * Dislikes: 45
 * Total Accepted:    274.6K
 * Total Submissions: 596.1K
 * Testcase Example:
 '["Trie","insert","search","search","startsWith","insert","search"]\n' +
  '[[],["apple"],["apple"],["app"],["app"],["app"],["app"]]'
 *
 * Implement a trie with insert, search, and startsWith methods.
 *
 * Example:
 *
 *
 * Trie trie = new Trie();
 *
 * trie.insert("apple");
 * trie.search("apple");   // returns true
 * trie.search("app");     // returns false
 * trie.startsWith("app"); // returns true
 * trie.insert("app");
 * trie.search("app");     // returns true
 *
 *
 * Note:
 *
 *
 * You may assume that all inputs are consist of lowercase letters a-z.
 * All inputs are guaranteed to be non-empty strings.
 *
 *
 */

// @lc code=start

class Trie {
  //   unordered_map<char, Trie*> cs;
  Trie* cs[26] = {nullptr};
  bool tail = false;

 public:
  /** Initialize your data structure here. */
  Trie() {}

  /** Inserts a word into the trie. */
  void insert(string word) {
    if (!word.length()) {
      tail = true;
      return;
    }
    Trie* p = this;

    for (char c : word) {
      int k = c - 'a';
      if (p->cs[k])
        p = p->cs[k];
      else {
        Trie* n = new Trie();
        p->cs[k] = n;
        p = n;
      }
    }
    p->tail = true;
  }

  /** Returns if the word is in the trie. */
  bool search(string word) {
    Trie* p = this;
    for (char c : word) {
      int k = c - 'a';
      if (p->cs[k])
        p = p->cs[k];
      else
        return false;
    }
    return p->tail;
  }

  /** Returns if there is any word in the trie that starts with the given
   * prefix. */
  bool startsWith(string prefix) {
    Trie* p = this;
    for (char c : prefix) {
      int k = c - 'a';
      if (p->cs[k])
        p = (p->cs)[k];
      else
        return false;
    }
    return true;
  }
};

static auto fastio = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end
