#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int totalWaviness(int num1, int num2)
	{
		vector<int> num;
		int ans = 0;
		for (int k = num1; k <= num2; ++k) {
			num.clear();
			int t = k;
			while (t) {
				num.push_back(t % 10);
				t /= 10;
			}
			int n = num.size();
			for (int i = 1; i < n - 1; ++i) {
				if (num[i] < num[i - 1] && num[i] < num[i + 1])
					ans++;
				if (num[i] > num[i - 1] && num[i] > num[i + 1])
					ans++;
			}
		}
		return ans;
	}
};
