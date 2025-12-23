#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int eatenApples(vector<int> &apples, vector<int> &days)
	{
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

		int n = apples.size(), ans = 0, day = 0;
		while (!pq.empty() || day < n) {
			if (day < n && apples[day]) pq.push({day + days[day], apples[day]});
			// remove rotten apples
			while (!pq.empty() && pq.top().first <= day) pq.pop();

			// eat apple, update heap top
			if (!pq.empty()) {
				auto [lastday, apple] = pq.top();
				pq.pop();
				ans++;
				if (apple > 1) pq.push({lastday, apple - 1});
			}
			day++;
		}
		return ans;
	}
};
