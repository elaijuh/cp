#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	string maxSumOfSquares(int num, int sum)
	{
		if (sum > 9 * num)
			return "";
		string s;
		for (int i = 9; i >= 1; --i) {
			int a = sum / i, b = sum % i;
			if (a == 0)
				continue;
			s.append(a, i + '0');
			num -= a;
			if (num >= 1) {
				s.append(1, b + '0');
				num -= 1;
			}
			if (num > 0)
				s.append(num, '0');
			break;
		}
		return s;
	}
};
