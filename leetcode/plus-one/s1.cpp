#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> plusOne(vector<int> &digits)
	{
		int n = digits.size();
		int k = 1;
		for (int i = n - 1; i >= 0; --i) {
			if (k) {
				digits[i]++;
				k = 0;
			}
			k = digits[i] / 10;
			digits[i] %= 10;
		}
		if (k)
			digits.insert(digits.begin(), 1);
		return digits;
	}
}
