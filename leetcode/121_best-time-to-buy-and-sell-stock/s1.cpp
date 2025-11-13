#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int> &prices)
	{
		int min = prices[0], ans = 0;
		for (int x : prices) {
			if (x < min)
				min = x;
			else if (x - min > ans)
				ans = x - min;
		}
		return ans;
	}
};
