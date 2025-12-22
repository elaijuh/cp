#include <bits/stdc++.h>
using namespace std;

class Solution {
	long long ans = 0;
	vector<vector<int>> g;
	array<int, 21> grp_cnt{};
	vector<int> *grp;

	array<int, 21> dfs(int u, int p)
	{
		array<int, 21> cnt{};
		cnt[(*grp)[u]] = 1;
		for (int x : g[u]) {
			if (x == p) continue;
			auto c = dfs(x, u);
			for (int i = 1; i <= 20; ++i) {
				if (grp_cnt[i]) ans += 1LL * c[i] * (grp_cnt[i] - c[i]);
				cnt[i] += c[i];
			}
		}
		return cnt;
	}

public:
	long long interactionCosts(int n, vector<vector<int>> &edges, vector<int> &group)
	{
		g.assign(n, {});
		for (auto &e : edges) {
			g[e[0]].push_back(e[1]);
			g[e[1]].push_back(e[0]);
		}
		grp = &group;
		for (int x : *grp) grp_cnt[x]++;
		dfs(0, -1);
		return ans;
	}
};
