#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int minimumFlips(int n)
	{
		vector<char> s;
		while (n) {
			if (n % 2)
				s.push_back('1');
			else
				s.push_back('0');
			n /= 2;
		}
		int sn = s.size();
		int ans = 0;
		for (int i = 0; i < sn / 2; ++i)
			if (s[i] != s[sn - i - 1])
				ans += 2;
		return ans;
	}
};
