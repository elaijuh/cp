#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	using ll = long long;
	int mostBooked(int n, vector<vector<int>> &meetings)
	{
		sort(meetings.begin(), meetings.end());
		priority_queue<int, vector<int>, greater<int>> pq_free;
		priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq_use;
		vector<int> cnt(n);
		for (int i = 0; i < n; ++i) pq_free.push(i);
		for (auto m : meetings) {
			int s = m[0], e = m[1];
			// move completed rooms to pq_free
			while (!pq_use.empty() && pq_use.top().first <= s) {
				auto [tope, topi] = pq_use.top();
				pq_use.pop();
				pq_free.push(topi);
			}
			// pick a room from pq_free
			if (!pq_free.empty()) {
				int topi = pq_free.top();
				pq_free.pop();
				pq_use.emplace(e, topi);
				cnt[topi]++;
			}
			else {	// update soonest room from pq_use
				auto [tope, topi] = pq_use.top();
				pq_use.pop();
				pq_use.emplace(tope + e - s, topi);
				cnt[topi]++;
			}
		}
		int ma = -1, ans = 0;
		for (int i = 0; i < n; ++i) {
			if (cnt[i] > ma) {
				ma = cnt[i];
				ans = i;
			}
		}
		return ans;
	}
};
