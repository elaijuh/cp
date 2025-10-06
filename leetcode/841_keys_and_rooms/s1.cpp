class Solution {
  public:
	bool dfs(int a, vector<vector<int>> &rooms) {
		bool visited[1001] = {false};
		int n = 0;
		stack<int> s;
		s.push(0);
		visited[0] = true;
		n++;
		while (!s.empty()) {
			int x = s.top();
			s.pop();
			for (int const &adj : rooms[x]) {
				if (!visited[adj]) {
					s.push(adj);
					visited[adj] = true;
					n++;
				}
			}
		}
		return n == rooms.size();
	}

	bool canVisitAllRooms(vector<vector<int>> &rooms) { return dfs(0, rooms); }
};
