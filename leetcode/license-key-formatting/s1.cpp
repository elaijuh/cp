#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	string licenseKeyFormatting(string s, int k)
	{
		string ans = "";
		int step = 0;
		for (int i = s.size() - 1; i >= 0; --i) {
			if (s[i] == '-')
				continue;
			ans.push_back(toupper(s[i]));
			step++;
			if (step == k) {
				ans.push_back('-');
				step = 0;
			}
		}
		if (ans.size() && ans.back() == '-')
			ans.pop_back();
		reverse(begin(ans), end(ans));
		return ans;
	}
}
