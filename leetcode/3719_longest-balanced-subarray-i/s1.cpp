#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int longestBalanced(vector<int> &nums)
	{
		int res = 0;
		int n = nums.size();
		for (int i = 0; i < n; i++) {
			queue<int> odd, even;
			unordered_map<int, bool> foundEven, foundOdd;
			if (n - i < res)
				return res;
			for (int j = i; j < n; j++) {
				if (nums[j] % 2 == 0 && !foundEven[nums[j]]) {
					foundEven[nums[j]] = true;
					even.push(nums[j]);
				}
				else if (nums[j] % 2 != 0 && !foundOdd[nums[j]]) {
					foundOdd[nums[j]] = true;
					odd.push(nums[j]);
				}

				if (odd.size() == even.size()) {
					res = max(j - i + 1, res);
					cout << res;
				}
			}
		}
		return res;
	}
};
