#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> countMentions(int N, vector<vector<string>> &events)
	{
		vector<int> ans(N, 0);
		unordered_map<int, int> off;
		sort(events.begin(), events.end(), [](vector<string> &a, vector<string> &b) {
			if (a[1] == b[1])
				return a[0] > b[0];
			return stoi(a[1]) < stoi(b[1]);
		});
		for (vector<string> &v : events) {
			if (v[0] == "OFFLINE") {
				off[stoi(v[2])] = stoi(v[1]);
				continue;
			}
			if (v[2] == "ALL") {
				for (int &x : ans) x++;
			}
			else if (v[2] == "HERE") {
				for (int i = 0; i < N; ++i) {
					if (!off.count(i))
						ans[i]++;
					else {
						if (off[i] + 60 <= stoi(v[1])) {
							ans[i]++;
							off.erase(i);
						}
					}
				}
			}
			else {
				stringstream ss(v[2]);
				vector<int> ids;
				string id;
				while (ss >> id) {
					ids.push_back(stoi(id.substr(2)));
				}
				for (int &x : ids) ans[x]++;
			}
		}
		return ans;
	}
}
