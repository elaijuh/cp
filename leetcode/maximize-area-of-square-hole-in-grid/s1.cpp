#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int maximizeSquareHoleArea(int n, int m, vector<int> &hBars, vector<int> &vBars)
	{
		sort(hBars.begin(), hBars.end());
		sort(vBars.begin(), vBars.end());
		int hx = 0, hy = 0, vx = 0, vy = 0, hl = 0, vl = 0;
		for (int i = 1; i < hBars.size(); ++i) {
			if (hBars[i] == hBars[i - 1] + 1)
				hy = i;
			else
				hx = hy = i;
			hl = max(hl, hy - hx);
		}
		for (int i = 1; i < vBars.size(); ++i) {
			if (vBars[i] == vBars[i - 1] + 1)
				vy = i;
			else
				vx = vy = i;
			vl = max(vl, vy - vx);
		}
		int l = min(hl, vl);
		return (l + 2) * (l + 2);
	}
};
