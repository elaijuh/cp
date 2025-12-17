#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int repeatedStringMatch(string a, string b)
	{
		int k = b.size() / a.size();
		int ans = 1;
		string ss = a;
		while (ss.size() < b.size()) {
			ss += a;
			ans++;
		}
		if (ss.find(b) != ss.npos)
			return ans;
		ss += a;
		if (ss.find(b) != ss.npos)
			return ans + 1;
		return -1;
	}
};
