// OJ: https://leetcode.com/problems/word-search-ii/
// Author: github.com/elaijuh
// Time: O(m*n*sum_of_chars(words))
// Space: O(sum_of_chars(words))
struct TrieNode {
  unordered_map<char, TrieNode*> children;
  bool tail;
  TrieNode() : tail(false) {}
  void insert(string s) {
    TrieNode* p = this;
    for (char c : s) {
      if (!p->children[c]) p->children[c] = new TrieNode();
      p = p->children[c];
    }
    p->tail = true;
  }
};
class Solution {
  unordered_set<string> ans;

 public:
  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    TrieNode* t = new TrieNode();
    for (string s : words) t->insert(s);
    for (int i = 0; i < board.size(); ++i)
      for (int j = 0; j < board[0].size(); ++j) dfs(board, i, j, t, "");
    return vector<string>(ans.begin(), ans.end());
  }
  void dfs(vector<vector<char>>& board, int i, int j, TrieNode* t, string s) {
    char c = board[i][j];
    if (c == '*') return;
    board[i][j] = '*';
    TrieNode* p = t->children[c];
    if (p) {
      string ss = s + c;
      if (p->tail) ans.insert(ss);
      if (i > 0) dfs(board, i - 1, j, p, ss);
      if (i < board.size() - 1) dfs(board, i + 1, j, p, ss);
      if (j > 0) dfs(board, i, j - 1, p, ss);
      if (j < board[0].size() - 1) dfs(board, i, j + 1, p, ss);
    }
    board[i][j] = c;
  }
};
