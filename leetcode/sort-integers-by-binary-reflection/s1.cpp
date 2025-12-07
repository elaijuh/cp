#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> sortByReflection(vector<int> &nums)
	{
		sort(nums.begin(), nums.end(), [&](const int &a, const int &b) {
			int da = a, db = b, ra = 0, rb = 0;
			while (da) {
				ra = ra << 1 | (da & 1);
				da >>= 1;
			}
			while (db) {
				rb = rb << 1 | (db & 1);
				db >>= 1;
			}
			if (ra == rb)
				return a < b;
			return ra < rb;
		});
		return nums;
	}
};
