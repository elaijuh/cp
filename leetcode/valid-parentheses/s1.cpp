#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool isValid(string s)
	{
		stack<char> stk;
		for (char c : s) {
			if (stk.empty()) {
				stk.push(c);
				continue;
			}
			char cc = stk.top();
			if (c == ')' && cc == '(' || c == ']' && cc == '[' || c == '}' && cc == '{')
				stk.pop();
			else
				stk.push(c);
		}
		return stk.empty();
	}
};
