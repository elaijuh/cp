#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	string removeDuplicateLetters(string s)
	{
		unordered_map<char, int> mp;
		unordered_set<char> st;
		string stk;
		int n = s.size();
		for (int i = 0; i < n; ++i) mp[s[i]] = i;
		for (int i = 0; i < n; ++i) {
			if (st.count(s[i]))
				continue;
			while (!stk.empty() && s[i] < stk.back() && mp[stk.back()] > i) {
				st.erase(stk.back());
				stk.pop_back();
			}
			stk.push_back(s[i]);
			st.insert(s[i]);
		}
		return stk;
	}
}
