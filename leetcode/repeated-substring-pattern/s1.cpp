#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool repeatedSubstringPattern(string s)
	{
		string ss = s + s;
		return ss.substr(1, ss.size() - 2).contains(s);
	}
};
