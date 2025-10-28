#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	bool wordPattern(string pattern, string s)
	{
		vector<string> sv;
		unordered_map<char, string> ma;
		unordered_map<string, char> mb;
		istringstream iss(s);
		string t;
		while (iss >> t) sv.push_back(t);
		if (pattern.size() != sv.size())
			return false;
		int n = pattern.size();
		for (int i = 0; i < n; ++i) {
			if (ma.find(pattern[i]) == ma.end() && mb.find(sv[i]) == mb.end()) {
				ma[pattern[i]] = sv[i];
				mb[sv[i]] = pattern[i];
			}
			else if (ma.find(pattern[i]) == ma.end() && pattern[i] != mb[sv[i]])
				return false;
			else if (ma[pattern[i]] != sv[i])
				return false;
		}
		return true;
	}
};
