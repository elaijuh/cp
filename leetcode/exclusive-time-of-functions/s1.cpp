#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> exclusiveTime(int n, vector<string> &logs)
	{
		vector<int> res(n, 0);
		vector<pair<int, int>> st;
		for (string s : logs) {
			int id, time, d;
			bool is_start;
			stringstream ss(s);
			string ts;
			getline(ss, ts, ':');
			id = stoi(ts);
			getline(ss, ts, ':');
			is_start = ts == "start" ? true : false;
			getline(ss, ts, ':');
			time = stoi(ts);
			if (is_start) {
				st.push_back({id, time});
			}
			else {
				auto [pid, ptime] = st.back();
				st.pop_back();
				d = time - ptime + 1;
				res[pid] += d;
				if (!st.empty())
					res[st.back().first] -= d;
			}
		}
		return res;
	}
};
