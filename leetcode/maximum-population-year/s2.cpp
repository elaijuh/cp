#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int maximumPopulation(vector<vector<int>> &logs)
	{
		int n = logs.size();
		vector<pair<int, bool>> v;
		for (int i = 0; i < n; i++) {
			v.emplace_back(logs[i][0], true);
			v.emplace_back(logs[i][1], false);
		}
		sort(v.begin(), v.end());
		int ans, p = 0, maxp = 0;
		for (auto &x : v) {
			if (x.second)
				p++;
			else
				p--;
			if (p > maxp) {
				maxp = p;
				ans = x.first;
			}
		}
		return ans;
	}
};
