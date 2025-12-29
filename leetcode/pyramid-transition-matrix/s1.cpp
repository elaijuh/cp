#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	unordered_map<string, vector<char>> t;
	unordered_set<string> mem;
	bool ans = false;

	bool pyramidTransition(string bottom, vector<string> &allowed)
	{
		for (string &s : allowed) {
			t[s.substr(0, 2)].push_back(s[2]);
		}
		dfs(bottom);
		return ans;
	}

	void dfs(string s)
	{
		if (s.size() == 1) {
			ans = true;
			return;
		}
		if (ans || mem.count(s)) return;
		mem.insert(s);

		vector<string> children;
		children.push_back("");
		// construct all possible strings for above row
		for (int i = 0; i < s.size() - 1; ++i) {
			string k = s.substr(i, 2);
			if (!t.count(k)) return;
			vector<string> c;
			for (char &ch : t[k]) {
				for (string &child : children) {
					c.push_back(child + ch);
				}
			}
			children = c;
		}

		for (string &s : children) dfs(s);
	}
};
