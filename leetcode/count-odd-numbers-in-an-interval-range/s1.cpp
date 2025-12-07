#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int countOdds(int low, int high)
	{
		int ans = 0;
		for (int i = low; i <= high; ++i) ans += i & 1;
		return ans;
	}
};
