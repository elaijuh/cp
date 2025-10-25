#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	string lexSmallest(string s)
	{
		int n = s.size();
		string ans(n, 'z');
		for (int k = 1; k <= n; ++k) {
			string s1 = s;
			reverse(s1.begin(), s1.begin() + k);
			ans = min(ans, s1);
			s1 = s;
			reverse(s1.end() - k, s1.end());
			ans = min(ans, s1);
		}
		return ans;
	}
};
