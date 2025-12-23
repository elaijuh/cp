#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int maximumPopulation(vector<vector<int>> &logs)
	{
		int psum[2051] = {0};
		for (auto &x : logs) {
			psum[x[0]]++;
			psum[x[1]]--;
		}
		int ans = 1950;
		for (int i = 1951; i <= 2050; ++i) {
			psum[i] += psum[i - 1];
			if (psum[i] > psum[ans]) ans = i;
		}
		return ans;
	}
};
