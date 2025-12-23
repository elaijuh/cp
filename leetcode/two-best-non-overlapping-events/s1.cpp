#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int maxTwoEvents(vector<vector<int>> &events)
	{
		priority_queue<pair<int, int>> pq;
		// max heap {val,start}
		for (auto &e : events) pq.emplace(e[2], e[0]);
		sort(events.begin(), events.end(), [](vector<int> &a, vector<int> &b) {
			return a[1] < b[1];
		});

		int ans = 0;
		for (auto &e : events) {
			int val = e[2];
			while (!pq.empty() && pq.top().second <= e[1]) pq.pop();
			if (!pq.empty()) val += pq.top().first;
			ans = max(ans, val);
		}
		return ans;
	}
};
