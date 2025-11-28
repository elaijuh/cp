#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> getConcatenation(vector<int> &nums)
	{
		vector<int> res(nums);
		res.insert(res.begin(), nums.begin(), nums.end());
		return res;
	}
}
