#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int maxDistinct(string s)
	{
		unordered_map<char, bool> mp;
		int n = s.length();
		int res = 0;
		for (int i = 0; i < n; ++i) {
			if (!mp.count(s[i])) {
				mp[s[i]] = true;
				res++;
			}
		}
		return res;
	}
};
