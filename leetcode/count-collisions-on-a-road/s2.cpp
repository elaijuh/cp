#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int countCollisions(string directions)
	{
		int n = directions.size();
		if (n == 1)
			return 0;
		int l = 0, r = n - 1;
		int ans = 0;
		while (l < n && directions[l] == 'L') l++;
		while (r >= 0 && directions[r] == 'R') r--;
		if (l >= r)
			return 0;
		while (l <= r) {
			while (directions[l] == 'R') {
				l++;
				ans++;
			}
			if (directions[l] == 'L')
				ans++;
			l++;
		}
		return ans;
	}
};
