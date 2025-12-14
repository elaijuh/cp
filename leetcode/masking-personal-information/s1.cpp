#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	string maskPII(string s)
	{
		string ans = "";
		int at = s.find('@');
		if (at != string::npos) {
			ans = ans + s[0] + "*****" + s[at - 1] + s.substr(at);
			transform(ans.begin(), ans.end(), ans.begin(), [](unsigned char c) { return tolower(c); });
			return ans;
		}
		int n = s.length();
		int count = 0;
		for (int i = n - 1; i >= 0; --i) {
			if (s[i] >= '0' && s[i] <= '9') {
				if (count < 4) {
					ans.push_back(s[i]);
					if (count == 3)
						ans.push_back('-');
				}
				else if (count >= 4 && count < 10) {
					ans.push_back('*');
					if (count == 6 || count == 9)
						ans.push_back('-');
				}
				else
					ans.push_back('*');
				count++;
			}
		}
		if (count >= 11)
			ans.push_back('+');
		else
			ans.pop_back();
		reverse(ans.begin(), ans.end());
		return ans;
	}
};
