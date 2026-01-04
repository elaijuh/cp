#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<vector<string>> wordSquares(vector<string> &words)
	{
		int n = words.size();
		vector<vector<string>> ans;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (words[j] == words[i]) continue;
				if (words[j][0] != words[i][0]) continue;
				for (int k = 0; k < n; ++k) {
					if (words[k] == words[j] || words[k] == words[i]) continue;
					if (words[k][0] != words[i][3]) continue;
					for (int l = 0; l < n; ++l) {
						if (words[l] == words[k] || words[l] == words[j] || words[l] == words[i]) continue;
						if (words[l][0] != words[j][3] || words[l][3] != words[k][3]) continue;
						vector<string> ss = {words[i], words[j], words[k], words[l]};
						ans.push_back(ss);
					}
				}
			}
		}
		sort(ans.begin(), ans.end());
		return ans;
	}
};
