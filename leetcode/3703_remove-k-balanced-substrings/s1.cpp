#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	string removeSubstring(string s, int k)
	{
		stack<pair<char, int>> stk;
		for (char c : s) {
			if (!stk.empty() && stk.top().first == c)
				stk.top().second++;
			else
				stk.push({c, 1});

			if (stk.size() >= 2) {
				auto &x = stk.top();
				stk.pop();
				auto &y = stk.top();
				if (x.first == ')' && x.second == k && y.second >= k) {
					y.second -= k;
					if (!y.second)
						stk.pop();
				}
				else {
					stk.push(x);
				}
			}
		}
		string res = "";
		while (!stk.empty()) {
			auto x = stk.top();
			res += string(x.second, x.first);
			stk.pop();
		}
		reverse(res.begin(), res.end());
		return res;
	}
};
