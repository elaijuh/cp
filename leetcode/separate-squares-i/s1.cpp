#include <bits/stdc++.h>
using namespace std;

// binary_search
class Solution {
public:
	double separateSquares(vector<vector<int>> &squares)
	{
		double total_area = 0, maxy = 0;
		for (auto &sq : squares) {
			total_area += (double)sq[2] * sq[2];
			maxy = max(maxy, (double)(sq[1] + sq[2]));
		}

		// calculate the area below yline
		auto check = [&](double yline) -> bool {
			double area = 0;
			for (auto &sq : squares) {
				int y = sq[1], l = sq[2];
				if (y < yline) {
					area += l * min(yline - y, (double)l);
				}
			}
			return area >= total_area / 2;
		};

		double l = 0, h = maxy;
		while (abs(h - l) > 1e-5) {
			double m = (h + l) / 2;
			if (check(m))
				h = m;
			else
				l = m;
		}
		return h;
	}
};
