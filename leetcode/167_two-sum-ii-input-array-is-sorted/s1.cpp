#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int> &numbers, int target)
	{
		int i = 0, j = numbers.size() - 1;
		vector<int> ans;
		while (i < j) {
			if (numbers[i] + numbers[j] > target)
				j--;
			else if (numbers[i] + numbers[j] < target)
				i++;
			else
				break;
		}
		ans.insert(ans.begin(), {i + 1, j + 1});
		return ans;
	}
}
