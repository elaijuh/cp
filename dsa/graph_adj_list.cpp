// https://wandbox.org/permlink/dy2hpeCegic0tsOJ
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

class Graph {
private:
	using weighted_edge = pair<int, int>;
	int V;
	vector<list<weighted_edge>> adj_list;

public:
	Graph(int vertices) : V(vertices)
	{
		adj_list.resize(vertices);
	}

	void add_edge(int u, int v, int weight)
	{
		adj_list[u].push_back({v, weight});

		// for undirected graph
		adj_list[v].push_back({u, weight});
	}

	void dfs(int root)
	{
		cout << "DFS\n";
		stack<int> s;
		vector<bool> vis(V, false);
		s.push(root);
		vis[root] = true;
		while (!s.empty()) {
			int u = s.top();
			cout << "Traverse to node: " << u << "\n";
			s.pop();
			for (auto [v, weight] : adj_list[u]) {
				if (!vis[v]) {
					vis[v] = true;
					s.push(v);
				}
			}
		}
	}

	void bfs(int root)
	{
		cout << "BFS\n";
		queue<int> q;
		vector<bool> vis(V, false);
		q.push(root);
		vis[root] = true;
		while (!q.empty()) {
			int u = q.front();
			cout << "Traverse to node: " << u << "\n";
			q.pop();
			for (auto [v, weight] : adj_list[u]) {
				if (!vis[v]) {
					vis[v] = true;
					q.push(v);
				}
			}
		}
	}

	void print()
	{
		for (int i = 0; i < V; ++i) {
			cout << "Vertex: " << i << " makes an edge with\n";
			for (auto &edge : adj_list[i]) {
				cout << "\tVertex " << edge.first << " with weight: " << edge.second << "\n";
			}
		}
	}
};

int main()
{
	Graph g(5);
	g.add_edge(0, 1, 10);
	g.add_edge(0, 4, 20);
	g.add_edge(1, 2, 30);
	g.add_edge(1, 3, 40);
	g.add_edge(1, 4, 50);
	g.add_edge(2, 3, 60);
	g.add_edge(3, 4, 70);

	g.print();

	g.bfs(0);
	g.dfs(0);
}
