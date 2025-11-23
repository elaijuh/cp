#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	typedef long long ll;
	long long sumAndMultiply(int n)
	{
		int i = 0;
		ll x = 0, sum = 0;
		while (n) {
			int r = n % 10;
			sum += r;
			if (r)
				x += r * pow(10, i++);
			n /= 10;
		}
		return x * sum;
	}
};
