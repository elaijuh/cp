#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int minLengthAfterRemovals(string s)
	{
		stack<char> stk;
		int n = s.length();
		for (int i = 0; i < n; ++i) {
			if (stk.empty() || s[i] == stk.top())
				stk.push(s[i]);
			else
				stk.pop();
		}
		return stk.size();
	}
}
