#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int sumFourDivisors(vector<int> &nums)
	{
		int ans = 0;
		for (int num : nums) {
			int s = 0, k = 0;
			for (int i = 1; i <= sqrt(num); ++i) {
				if (k > 4) break;
				if (num % i == 0) {
					if (i != num / i) {
						s += (i + num / i);
						k += 2;
					}
					else {
						s += i;
						k++;
					}
				}
			}
			if (k == 4) ans += s;
		}
		return ans;
	}
};
