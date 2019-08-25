#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

// adjacent list

#define MAXV 1000  // max number of vertices

class Graph {
  struct edgenode {
    int y;
    int weight;
    edgenode *next;
    edgenode(int y, int weight, edgenode *next)
        : y(y), weight(weight), next(next) {}
  };

  edgenode *edges[MAXV + 1];  // edges list
  int degree[MAXV + 1];       // number of edges connected to x
  int nvertices;              // number of vertices
  int nedges;                 // number of edges
  bool directed;

  unordered_map<int, bool> discovered;

 public:
  void setNvertices(int n) { nvertices = n; }
  int getNvertices() { return nvertices; }
  void initialize_graph(bool d) {
    nvertices = 0;
    nedges = 0;
    directed = d;
    for (int i = 0; i <= MAXV; i++) edges[i] = nullptr;
    for (int i = 0; i <= MAXV; i++) degree[i] = 0;
  }

  void insert_edge(int x, int y, bool directed) {
    edgenode *e = new edgenode(y, 0, edges[x]);
    edges[x] = e;
    degree[x]++;
    if (!directed) {
      insert_edge(y, x, true);
    } else {
      nedges++;
    }
  }

  void process_vertex_early(int v) { cout << v << " "; }
  void process_vertex_late(int v) {}

  void bfs(int start) {
    queue<int> q;
    discovered.clear();
    int v, y;
    edgenode *p;
    q.push(start);
    int discovered[MAXV + 1];
    discovered[start] = true;
    while (!q.empty()) {
      v = q.front();
      process_vertex_early(v);
      q.pop();
      p = edges[v];
      while (p != nullptr) {
        y = p->y;
        if (!discovered[y]) {
          q.push(y);
          discovered[y] = true;
        }
        p = p->next;
      }
    }
  }

  void _dfs(int v) {
    edgenode *p;
    int y;
    discovered[v] = true;
    process_vertex_early(v);
    p = edges[v];
    while (p != nullptr) {
      y = p->y;
      if (!discovered[y]) {
        _dfs(y);
      }
      p = p->next;
    }
  }

  void dfs(int v) {
    discovered.clear();
    _dfs(v);
  }
};

int main() {
  int n = 4, m = 4;
  int edges[MAXV + 1][2] = {{0, 1}, {1, 2}, {2, 3}, {3, 0}};
  Graph g;
  g.initialize_graph(false);
  g.setNvertices(n);
  for (int i = 0; i < m; i++) g.insert_edge(edges[i][0], edges[i][1], false);
  g.bfs(0);
  cout << endl;
  g.dfs(0);
  cout << endl;

  return 0;
}
