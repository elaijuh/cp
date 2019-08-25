/*
 * @lc app=leetcode id=127 lang=cpp
 *
 * [127] Word Ladder
 */
class Solution {
  struct Edgenode {
    int v;
    Edgenode* next;
    Edgenode(int v, Edgenode* p) : v(v), next(p) {}
  };

  struct Graph {
    unordered_map<int, Edgenode*> edges;
  };

  void insert_edge(Graph* g, int x, int y, bool directed) {
    Edgenode* p = new Edgenode(y, g->edges[x]);
    g->edges[x] = p;
    if (!directed) insert_edge(g, y, x, true);
  }

  vector<int> parent;
  vector<bool> discovered;

  void bfs(Graph* g, int start, int end) {
    queue<int> q;
    int x, v;
    Edgenode* p;
    q.push(start);
    discovered[start] = true;
    while (!q.empty()) {
      x = q.front();
      // process
      if (x == end) {
        return;
      }
      q.pop();
      p = g->edges[x];
      while (p != nullptr) {
        v = p->v;
        if (!discovered[v]) {
          q.push(v);
          discovered[v] = true;
          parent[v] = x;
        }
        p = p->next;
      }
    }
  }

  bool connected(const string& s1, const string& s2) {
    int n = s1.length();
    int k = 0;
    for (int i = 0; i < n; i++) {
      if (s1[i] != s2[i]) k++;
      if (k > 1) break;
    }
    return (k == 1);
  }

 public:
  int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    int n = wordList.size();
    int end = 0;
    for (; end < n; end++) {
      if (wordList[end] == endWord) break;
    }
    if (end >= n) return 0;
    wordList.insert(wordList.begin(), 1, beginWord);
    n++;
    end++;
    Graph* g = new Graph;
    for (int i = 0; i < n; i++) {
      parent.push_back(-1);
      discovered.push_back(false);
      for (int j = i + 1; j < n; j++) {
        if (connected(wordList[i], wordList[j])) {
          insert_edge(g, i, j, false);
        }
      }
    }
    bfs(g, 0, end);

    int k = 0;
    int pp = end;
    while (pp != -1) {
      k++;
      if (pp == 0) break;
      pp = parent[pp];
    }
    return pp == 0 ? k : 0;
  }
};
