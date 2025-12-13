#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<string> validateCoupons(vector<string> &code, vector<string> &businessLine, vector<bool> &isActive)
	{
		auto check_code = [](string &s) {
			if (!s.size())
				return false;
			for (char &c : s) {
				if (isalnum(c) || c == '_')
					continue;
				else
					return false;
			}
			return true;
		};

		auto check_bl = [](string &s) {
			return s == "electronics" || s == "grocery" || s == "pharmacy" || s == "restaurant";
		};

		vector<int> v;
		for (int i = 0; i < code.size(); ++i) {
			if (check_code(code[i]) && check_bl(businessLine[i]) && isActive[i])
				v.push_back(i);
		}
		sort(v.begin(), v.end(), [&](int &a, int &b) {
			if (businessLine[a] == businessLine[b])
				return code[a] < code[b];
			return businessLine[a] < businessLine[b];
		});
		vector<string> ans;
		for (int i : v) ans.push_back(code[i]);
		return ans;
	}
};
