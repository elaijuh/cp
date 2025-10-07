class Solution {
  public:
	int openLock(vector<string> &deadends, string target) {
		unordered_set<string> visited(deadends.begin(), deadends.end());
		queue<pair<string, int>> q;
		if (visited.find("0000") != visited.end())
			return -1;
		q.push({"0000", 0});
		visited.insert("0000");

		while (!q.empty()) {
			auto cur = q.front();
			q.pop();
			string c = cur.first;
			int n = cur.second;
			if (c == target)
				return n;
			for (int j = 0; j < 4; ++j) {
				string x = c;
				x[j] = (x[j] - '0' + 1) % 10 + '0';
				if (visited.find(x) == visited.end()) {
					q.push({x, n + 1});
					visited.insert(x);
				}
				x = c;
				x[j] = (x[j] - '0' + 9) % 10 + '0';
				if (visited.find(x) == visited.end()) {
					q.push({x, n + 1});
					visited.insert(x);
				}
			}
		}
		return -1;
	}
};
