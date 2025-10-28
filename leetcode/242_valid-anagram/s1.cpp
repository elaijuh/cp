#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	bool isAnagram(string s, string t)
	{
		unordered_map<char, int> mp;
		if (s.size() != t.size())
			return false;
		for (char &x : s) mp[x]++;
		for (char &x : t) {
			if (mp.find(x) == mp.end())
				return false;
			else if (!mp[x])
				return false;
			mp[x]--;
		}
		return true;
	}
};
