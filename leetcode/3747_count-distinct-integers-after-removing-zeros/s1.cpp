#include <bits/stdc++.h>
using namespace std;

lass Solution
{
public:
	typedef long long ll;

	long long countDistinct(long long n)
	{
		string s = to_string(n);
		int d = s.length();

		// s1. calculate up to d-1 digits
		ll ans = 9 * (pow(9, d - 1) - 1) / 8;

		// s2.
		ll t = 0;
		for (int i = 0; i < d; ++i) {
			if (s[i] == '0') {
				t--;
				break;
			}
			t += (int(s[i]) - 48 - 1) * pow(9, d - i - 1);
		}
		ans += t + 1;
		return ans;
	}
};
