#include <bits/stdc++.h>
using namespace std;

// scanning line
class Solution {
public:
	using ll = long long;
	double separateSquares(vector<vector<int>> &squares)
	{

		ll total_area = 0;
		// (y,l,flag)
		vector<tuple<int, int, int>> points;
		for (auto &sq : squares) {
			total_area += (ll)sq[2] * sq[2];
			points.emplace_back(sq[1], sq[2], 1);
			points.emplace_back(sq[1] + sq[2], sq[2], -1);
		}
		sort(points.begin(), points.end(), [](const auto &a, const auto &b) {
			return get<0>(a) < get<0>(b);
		});

		double width = 0;
		double curr_area = 0;
		double prev_height = 0;
		for (const auto &[y, l, delta] : points) {
			int diff = y - prev_height;
			double area = width * diff;
			// if this part of the area exceeds more than half of the total area
			if (2LL * (curr_area + area) >= total_area) {
				return prev_height +
					   (total_area - 2.0 * curr_area) / (2.0 * width);
			}
			// update width: add width at the start event, subtract width at the
			// end event
			width += delta * l;
			curr_area += area;
			prev_height = y;
		}
		return 0.0;
	}
};
