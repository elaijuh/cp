#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int countCoveredBuildings(int n, vector<vector<int>> &buildings)
	{
		unordered_map<int, pair<int, int>> mx, my;
		for (vector<int> &b : buildings) {
			if (!mx.count(b[0]))
				mx[b[0]] = {b[1], b[1]};
			else {
				mx[b[0]].first = min(mx[b[0]].first, b[1]);
				mx[b[0]].second = max(mx[b[0]].second, b[1]);
			}
			if (!my.count(b[1]))
				my[b[1]] = {b[0], b[0]};
			else {
				my[b[1]].first = min(my[b[1]].first, b[0]);
				my[b[1]].second = max(my[b[1]].second, b[0]);
			}
		}
		int ans = 0;
		for (auto &b : buildings) {
			if (mx[b[0]].first < b[1] && mx[b[0]].second > b[1] &&
				my[b[1]].first < b[0] && my[b[1]].second > b[0])
				ans++;
		}

		return ans;
	}
}
