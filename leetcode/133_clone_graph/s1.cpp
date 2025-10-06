/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
  public:
	Node *bfs(Node *a, vector<Node *> &visited) {
		Node *b = new Node(a->val);
		queue<Node *> q;
		q.push(a);
		visited[a->val] = b;
		while (!q.empty()) {
			Node *x = q.front();
			Node *y = visited[x->val];
			q.pop();
			for (Node *const adj : x->neighbors) {
				if (!visited[adj->val]) {
					Node *t = new Node(adj->val);
					y->neighbors.push_back(t);
					q.push(adj);
					visited[adj->val] = t;
				} else {
					y->neighbors.push_back(visited[adj->val]);
				}
			}
		}
		return b;
	}

	Node *dfs(Node *a, vector<Node *> &visited) {
		Node *b = new Node(a->val);
		stack<Node *> s;
		s.push(a);
		visited[a->val] = b;
		while (!s.empty()) {
			Node *x = s.top();
			Node *y = visited[x->val];
			s.pop();
			for (Node *const adj : x->neighbors) {
				if (!visited[adj->val]) {
					Node *t = new Node(adj->val);
					y->neighbors.push_back(t);
					s.push(adj);
					visited[adj->val] = t;
				} else {
					y->neighbors.push_back(visited[adj->val]);
				}
			}
		}
		return b;
	}

	Node *cloneGraph(Node *node) {
		vector<Node *> visited(101, nullptr);
		if (!node)
			return node;
		return bfs(node, visited);
		// return dfs(node, visited);
	}
};
