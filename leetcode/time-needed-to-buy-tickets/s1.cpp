#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int timeRequiredToBuy(vector<int> &tickets, int k)
	{
		queue<pair<int, int>> q;
		for (int i = 0; i < tickets.size(); ++i) q.push({i, tickets[i]});
		int ans = 0;
		while (!q.empty()) {
			auto [id, val] = q.front();
			q.pop();
			val--;
			ans++;
			if (id == k && val == 0)
				break;
			if (val)
				q.push({id, val});
		}
		return ans;
	}
}
