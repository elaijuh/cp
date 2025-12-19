#include <bits/stdc++.h>
using namespace std;

class UnionFind {
private:
	vector<int> parent;
	vector<int> rank;

public:
	UnionFind(int n)
	{
		parent.resize(n);
		rank.resize(n);
		for (int i = 0; i < n; ++i) parent[i] = i;
	}

	int find(int x)
	{
		if (parent[x] != x) {
			parent[x] = find(parent[x]);
		}
		return parent[x];
	}

	void uni(int x, int y)
	{
		int px = find(x);
		int py = find(y);
		if (px != py) {
			if (rank[px] > rank[py])
				parent[py] = px;
			else if (rank[px] < rank[py])
				parent[px] = py;
			else {
				parent[py] = px;
				rank[px]++;
			}
		}
	}

	bool connected(int x, int y)
	{
		return find(x) == find(y);
	}

	void reset(int x)
	{
		parent[x] = x;
		rank[x] = 0;
	}
};

class Solution {
public:
	vector<int> findAllPeople(int n, vector<vector<int>> &meetings, int firstPerson)
	{
		sort(meetings.begin(), meetings.end(), [](auto &a, auto &b) { return a[2] < b[2]; });
		map<int, vector<pair<int, int>>> mp;
		for (auto &m : meetings) {
			mp[m[2]].emplace_back(m[0], m[1]);
		}
		UnionFind g(n);
		g.uni(firstPerson, 0);
		for (auto &[t, meetings] : mp) {
			for (auto &[p1, p2] : meetings) {
				g.uni(p1, p2);
			}
			for (auto &[p1, p2] : meetings) {
				if (!g.connected(p1, 0)) {
					g.reset(p1);
					g.reset(p2);
				}
			}
		}
		vector<int> ans;
		for (int i = 0; i < n; ++i) {
			if (g.connected(i, 0))
				ans.push_back(i);
		}
		return ans;
	}
};
