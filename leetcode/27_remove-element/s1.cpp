#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int removeElement(vector<int> &nums, int val)
	{
		vector<int> a;
		for (int &x : nums)
			if (x != val)
				a.push_back(x);
		nums = a;
		return a.size();
	}
}
