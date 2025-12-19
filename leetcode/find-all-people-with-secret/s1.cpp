#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> findAllPeople(int n, vector<vector<int>> &meetings, int firstPerson)
	{
		unordered_map<int, vector<pair<int, int>>> g;
		for (auto &m : meetings) {
			g[m[0]].emplace_back(m[1], m[2]);
			g[m[1]].emplace_back(m[0], m[2]);
		}
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		pq.emplace(0, 0);
		pq.emplace(0, firstPerson);
		vector<bool> vis(n, false);

		// BFS
		while (!pq.empty()) {
			auto [ct, cp] = pq.top();
			pq.pop();
			if (vis[cp])
				continue;
			vis[cp] = true;
			for (auto [np, nt] : g[cp]) {
				if (nt >= ct && !vis[np]) {
					pq.emplace(nt, np);
				}
			}
		}
		vector<int> ans;
		for (int i = 0; i < n; ++i) {
			if (vis[i])
				ans.push_back(i);
		}
		return ans;
	}
}
