#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int findMaxConsecutiveOnes(vector<int> &nums)
	{
		int res = 0, k = 0;
		for (int x : nums)
			if (x) {
				k++;
				res = max(res, k);
			}
			else
				k = 0;
		return res;
	}
}
