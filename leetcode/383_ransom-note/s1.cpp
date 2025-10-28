#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool canConstruct(string ransomNote, string magazine)
	{
		unordered_map<char, int> mp;
		for (char &x : magazine) mp[x]++;
		for (char &x : ransomNote) {
			if (mp[x])
				mp[x]--;
			else
				return false;
		}
		return true;
	}
};
