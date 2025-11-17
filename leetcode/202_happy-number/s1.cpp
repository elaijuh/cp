#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool isHappy(int n)
	{
		int t = 0;
		unordered_map<int, bool> mp;
		while (t != 1) {
			t = 0;
			while (n != 0) {
				t += (n % 10) * (n % 10);
				n /= 10;
			}
			if (mp.find(t) != mp.end())
				return false;
			mp[t] = true;
			n = t;
		}
		return true;
	}
};
