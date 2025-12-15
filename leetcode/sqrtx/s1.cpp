#include <bits/stdc++.h>
using namespace std;
class Solution {

public:
	int mySqrt(int x)
	{
		int l = 0, r = 1 << 16;
		unsigned int pre, ans;
		while (l <= r) {
			ans = (l + r) / 2;
			if (ans * ans == x)
				return ans;
			if (ans * ans < x) {
				pre = ans;
				l = ans + 1;
			}
			else
				r = ans - 1;
		}
		if (ans * ans > x)
			return pre;
		return ans;
	}
};
