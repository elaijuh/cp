#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	long long maxMatrixSum(vector<vector<int>> &matrix)
	{
		int n = matrix.size();
		long long ans{0};
		int k = 0, m = INT_MAX;
		for (auto row : matrix) {
			for (int &x : row) {
				if (x > 0)
					ans += x;
				else {
					ans += -x;
					k++;
				}
				m = min(m, abs(x));
			}
		}
		if (k & 1) ans -= 2 * m;
		return ans;
	}
};
